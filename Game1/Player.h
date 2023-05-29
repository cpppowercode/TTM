#pragma once
class Player : public Actor
{
public:
	static Player* Create(string name = "Player");
    Player();
    virtual ~Player();

    // player's move velocity scalar
    float   scalar;
    // player's move velocity rotation seta
    // 근데 이거 seta 값을 ToRadian 해야하나 말아야하나 모름
    float   seta;

    //중력 scalar 값
    float   gravity;

    // 애니메이션 함수에 쓸 변수들
    class Actor* Ani;
    int src, dest;
    float t = 0.0f;

    //충돌 시에 이동함수에 추가될 방향값으로 기본값은 0
    Vector3 ObbColPos = Vector3(0.0f, 0.0f, 0.0f);


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

    // player's scalar and shooting rotation seta setting
    void    SetScalar(float scalar) { this->scalar = scalar; }
    void    SetSeta(float seta) { this->seta = seta; }

    // player's gravity get, set
    void    SetGravity(float gravity) { this->gravity = gravity; }
    float   GetGravity() { return gravity; }

    // player's Move WorldPos
    void    MovePlayer(float scalar, float seta);

    // if player's animation change, animation's pos setting
    void    PlayerAnimationPosSetting(Actor* Animation, int size);

    // animation function
    void Animation(GameObject* root);

    // 충돌시에 플레이어 이동 방향 변경용 벡터 설정
    void SetObbColPos(Vector3 pos) { this->ObbColPos = pos; }
};

