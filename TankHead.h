#pragma once
#include "Engine/GameObject.h"

class TankHead :
    public GameObject
{
private:
    int hModel_;
    //モデル自体はグローバル領域に保存されている
public:
    TankHead(GameObject* parent);

    ~TankHead();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    /// <summary>
    /// モデル番号を返す関数
    /// </summary>
    /// <returns>モデル番号</returns>
    int GetModelHandle(){return hModel_;}
};

