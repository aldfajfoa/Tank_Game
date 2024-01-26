#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//カメラ制御
enum CAM_TYPE
{
    FIXED_TYPE,//固定
    TPS_NOROT_TYPE,//三人称回転無し
    TPS_TYPE,//三人称
    FPS_TYPE,//一人称
    MAX_TYPE//番兵さん(チェック用の値)
};

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

    int GetCam() { return camState_; }
};

