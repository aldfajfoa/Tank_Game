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

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

