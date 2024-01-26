#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Enemy.h"
#include "Tank.h"

class PlayScene;

class HUD :
    public GameObject
{
    int hPict_;
    PlayScene* rm;
    Text* cText;
    Tank* cam;
public:
    HUD(GameObject* parent);

    ~HUD();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

