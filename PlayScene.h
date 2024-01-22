#pragma once
#include "Engine/GameObject.h"
#include "Enemy.h"
#include "Engine/Text.h"
#include "Tank.h"

class PlayScene :
    public GameObject
{
    int remaining;
    Text* eText;
    Enemy* p;
    Tank* player;
public:

    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    PlayScene(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void Decrease_remaining() { remaining -= 1; }
};

