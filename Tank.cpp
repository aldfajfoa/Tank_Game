#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Engine/Camera.h"
#include "Ground.h"
#include "TankHead.h"
#include "PlayScene.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1),
	speed_(0.1),front_({0,0,1,0}), camState_(FIXED_TYPE)
{
	
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Model\\TankBody.fbx");
	assert(hModel_ >= 0);
	Instantiate<TankHead>(this);
}

void Tank::Update()
{
	XMMATRIX rotY = XMMatrixIdentity();//行列の1 単位行列
	XMVECTOR move{0,0,0,0};
	XMVECTOR rotVec{ 0,0,0,0 };
	int dir = 0;

	if (Input::IsKey(DIK_W)){
		dir = 1.0;
	}
	if (Input::IsKey(DIK_S)){
		dir = -1.0;
	}

	if (Input::IsKey(DIK_A)) 
	{
		this->transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 1;
	}

	//回転行列を求める
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//ベクトルの回転結果を求める
	rotVec = XMVector3TransformCoord(front_, rotY);
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));

	pos = pos + dir * move;

	XMStoreFloat3(&(transform_.position_), pos);

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true) {
		transform_.position_.y = -data.dist;
	}

	if (Input::IsKeyDown(DIK_Z)) {
		camState_++;
		if (camState_ == CAM_TYPE::MAX_TYPE)
			camState_ = CAM_TYPE::FIXED_TYPE;
	}

	switch (camState_)
	{
	case FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3( 0,20,-20 ));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}
	case TPS_NOROT_TYPE:
	{
		XMFLOAT3 campos = transform_.position_;
		campos.y = transform_.position_.y + 15.0f;
		campos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(campos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case TPS_TYPE:
	{
		Camera::SetTarget(transform_.position_);
		XMVECTOR vEye{ 0,5,-10,0 };
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMFLOAT3 campos;
		XMStoreFloat3(&campos, pos + vEye);
		Camera::SetPosition(campos);
		break;
	}
	case FPS_TYPE:
	{
		//Camera::SetTarget(transform_.position_);
		//XMFLOAT3 camTarget;

		//XMVECTOR vMove = XMLoadFloat3(&());
		//XMStoreFloat3(&camTarget, pos + dir * move);
		//Camera::SetPosition(camTarget);
		break;
	}
	default:
		break;
	
	}
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
