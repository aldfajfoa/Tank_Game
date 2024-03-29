#pragma once
#include "Engine/GameObject.h"
#include "Ground.h"

class PlayScene;

class Enemy :
    public GameObject
{
    PlayScene* en;
    int hModel_;
public:
    Enemy(GameObject* parent);

    ~Enemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
   //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;
};

