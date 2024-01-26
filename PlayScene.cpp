#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
#include "HUD.h"
#include "Engine/SceneManager.h"

namespace {
	const int enemyNum_ = 5;
}

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);

	for (int i = 0; i < enemyNum_; i++) {
		p = Instantiate<Enemy>(this);
		p->SetPosition((rand() % 50)-25, 0.5, (rand() % 50)-25);
	}

	Instantiate<HUD>(this);

	remaining = enemyNum_;
}

void PlayScene::Update()
{
	if (remaining == 0) {
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
