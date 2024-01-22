#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent,"Ground"),hModel_(-1)
{
}

Ground::~Ground()
{
}

void Ground::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Model\\Ground.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Ground::Release()
{
}
