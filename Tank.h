#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Tank :
    public GameObject
{
    Text* cText;
    int hModel_;//モデル番号
    XMVECTOR front_;//前ベクトル z+方向 大きさ1
    float speed_;
    int camState_;
public:
    //コンストラクタ
    Tank(GameObject* parent);
    int hPict_;

    //デストラクタ
    ~Tank();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

