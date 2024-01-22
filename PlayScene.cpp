#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

namespace {
	const int enemyNum_ = 30;
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

	remaining = enemyNum_;
	eText = new Text;
	eText->Initialize();
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
	eText->Draw(30, 65, remaining);
}

void PlayScene::Release()
{
}
