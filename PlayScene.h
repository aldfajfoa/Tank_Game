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

    void Decrease_remaining() { remaining -= 1; }
};

