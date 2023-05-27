#pragma once
class Player : public Actor
{
public:
	static Player* Create(string name = "Player");
    Player();
    virtual ~Player();

    
public:
    void	Update() override;
    void	Release() override;
    
    //플레이어 root 위치
    Vector3 GetPlayerWorldPos();
    void    SetPlayerWorldPos(Vector3 pos);

    //플레이어 root 회전값
    void    SetPlayerRotationX(float rot);
    void    SetPlayerRotationY(float rot);
    void    SetPlayerRotationZ(float rot);

    float   GetPlayerRotationX();
    float   GetPlayerRotationY();
    float   GetPlayerRotationZ();
};

