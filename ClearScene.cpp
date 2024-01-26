#include "ClearScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"

ClearScene::ClearScene(GameObject* parent)
    :GameObject(parent, "ClearScene"), hPict_(-1)
{

}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
    hPict_ = Image::Load("CLEAR.png");
    assert(hPict_ >= 0);
}

void ClearScene::Update()
{
    if (Input::IsMouseButtonDown(0))
    {
        SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
        pSM->ChangeScene(SCENE_ID::SCENE_ID_TITLE);
    }
}

void ClearScene::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

void ClearScene::Release()
{
}
