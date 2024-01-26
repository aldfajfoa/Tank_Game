#include "HUD.h"
#include "PlayScene.h"
#include "Engine/Image.h"

HUD::HUD(GameObject* parent)
	:GameObject(parent, "HUD"),hPict_(-1)
{
}

HUD::~HUD()
{
}

void HUD::Initialize()
{
	hPict_ = Image::Load("remaining.png");
	assert(hPict_ >= 0);

	cText = new Text;
	cText->Initialize();

	cam = (Tank*)FindObject("Tank");

	rm = (PlayScene*)GetParent();
}

void HUD::Update()
{
	transform_.scale_ = { 0.4, 0.4 ,1 };
	transform_.position_ = { -0.82, 0.79 ,1};
}

void HUD::Draw()
{
	switch (cam->GetCam()) {
	case FIXED_TYPE: {
		cText->Draw(30, 30, "FIXED");
		break;
	}
	case TPS_NOROT_TYPE: {
		cText->Draw(30, 30, "TPS_NOROT");
		break;
	}
	case TPS_TYPE: {
		cText->Draw(30, 30, "TPS");
		break;
	}
	case FPS_TYPE: {
		cText->Draw(30, 30, "FPS");
		break;
	}
	default:
		break;
	}

	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	cText->Draw(150, 74, rm->Getremaining());
}

void HUD::Release()
{
}
