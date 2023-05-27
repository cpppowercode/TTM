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
    
    //�÷��̾� root ��ġ
    Vector3 GetPlayerWorldPos();
    void    SetPlayerWorldPos(Vector3 pos);

    //�÷��̾� root ȸ����
    void    SetPlayerRotationX(float rot);
    void    SetPlayerRotationY(float rot);
    void    SetPlayerRotationZ(float rot);

    float   GetPlayerRotationX();
    float   GetPlayerRotationY();
    float   GetPlayerRotationZ();
};

