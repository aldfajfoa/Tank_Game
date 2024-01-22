#pragma once
#include "Engine/GameObject.h"
#include "Ground.h"
#include "PlayScene.h"

class Enemy :
    public GameObject
{
    PlayScene* en;
    int hModel_;
public:
    Enemy(GameObject* parent);

    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
   //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;
};

