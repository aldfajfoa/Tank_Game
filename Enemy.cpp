#include "Enemy.h"
#include "Engine/Model.h"
#include "PlayScene.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\mashroom.fbx");
	assert(hModel_ >= 0);

	//アニメーションのセット
	Model::SetAnimFrame(hModel_, 1, 60, 1);
	float x = (float)rand() / RAND_MAX;//0～1の乱数

	x = 2.0 * x;
	float z = (float)rand() / RAND_MAX;
	z = 2.0 * z;

	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 1.0f);
	AddCollider(collision);

	en = (PlayScene*)GetParent();
}

void Enemy::Update()
{
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true) {
		transform_.position_.y = -data.dist+0.4;
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		this->KillMe();
		pTarget->KillMe();
		en->Decrease_remaining();
	}
}
