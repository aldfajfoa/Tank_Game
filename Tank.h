#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�J��������
enum CAM_TYPE
{
    FIXED_TYPE,//�Œ�
    TPS_NOROT_TYPE,//�O�l�̉�]����
    TPS_TYPE,//�O�l��
    FPS_TYPE,//��l��
    MAX_TYPE//�ԕ�����(�`�F�b�N�p�̒l)
};

class Tank :
    public GameObject
{
    Text* cText;
    int hModel_;//���f���ԍ�
    XMVECTOR front_;//�O�x�N�g�� z+���� �傫��1
    float speed_;
    int camState_;
public:
    //�R���X�g���N�^
    Tank(GameObject* parent);
    int hPict_;

    //�f�X�g���N�^
    ~Tank();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    int GetCam() { return camState_; }
};

