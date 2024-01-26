#pragma once
#include "Engine/GameObject.h"
#include "Enemy.h"
#include "Engine/Text.h"
#include "Tank.h"

class PlayScene :
    public GameObject
{
    int remaining;
    Enemy* p;
    Tank* player;
public:

    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    PlayScene(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    int Getremaining() { return remaining; }

    void Decrease_remaining() { remaining --; }//敵の数を減らす
};

