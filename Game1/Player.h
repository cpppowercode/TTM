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
    Vector3   seta;
    float   gravity;

    class Actor* Ani;
    int src, dest;
    float t = 0.0f;

    bool IsFire;

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
    void    SetSeta(Vector3 seta) { this->seta = seta; }

    // player's gravity get, set
    void    SetGravity(float gravity) { this->gravity = gravity; }
    float   GetGravity() { return gravity; }

    // player's Move WorldPos
    void    MovePlayer(float scalar, Vector3 seta);

    // if player's animation change, animation's pos setting
    void    PlayerAnimationPosSetting(Actor* Animation, int size);

    // animation function
    void Animation(GameObject* root);
};

