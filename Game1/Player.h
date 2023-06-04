#pragma once
class Player : public Actor
{
public:
	static Player* Create(string name = "Player");
    Player();
    virtual ~Player();

    
    // �߷�
    float   gravity;

    //������ ���� ������.
    float   BoosterScalar;

    //�ִϸ��̼ǿ� ������
    class Actor* Ani[4];
    int src, dest;
    float t = 0.0f;

    bool IsFire;

    // �ӵ�, ũ��
    Vector3 velocity;
    float   scalar;

    // �ʱ� ���Ⱚ
    Vector3 seta;

    // �ʱ� ���Ⱚ + �¿�Ű ���� ���� ��ȭ��   
    Vector3 velocityDir;

    // �¿�Ű �������� ���ϴ� ���Ⱚ
    Vector3 ChangeVel;
    bool IsChange;
    float rt = 0.0f;

    // ����Ű �������� ���ϴ� ���Ⱚ
    bool  PressWS;
    float ChangeWS;
    float rt_x = 0.0f;

public:
    void	Update() override;
    void	Release() override;

    //player root worldPos
    Vector3 GetPlayerWorldPos();
    void    SetPlayerWorldPos(Vector3 pos);

    //player root rotation
    void    SetPlayerRotationX(float rot);
    void    SetPlayerRotationY(float rot);
    void    SetPlayerRotationZ(float rot);

    float   GetPlayerRotationX();
    float   GetPlayerRotationY();
    float   GetPlayerRotationZ();

    // player's scalar setting
    void    SetScalar(float scalar) { this->scalar = scalar; }

    // player's gravity get, set
    void    SetGravity(float gravity) { this->gravity = gravity; }
    float   GetGravity() { return gravity; }

    // player's Move WorldPos
    void    MovePlayer();

    // if player's animation change, animation's pos setting
    void    PlayerAnimationPosSetting(Actor* Animation, int size);

    // animation function
    void Animation(GameObject* root);

    void ChangeAni();

    // velocity ����
    void SetVelocity();
    Vector3 GetVelocity() { this->velocity = velocity; }
};

