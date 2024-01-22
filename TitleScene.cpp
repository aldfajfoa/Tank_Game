#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"

TitleScene::TitleScene(GameObject* parent)
{
}

void TitleScene::Initialize()
{
	hPict_ = Image::Load("TITLE.png");
	assert(hPict_ >= 0);
}

void TitleScene::Update()
{
	if (Input::IsMouseButtonDown(0))
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void TitleScene::Release()
{
}
