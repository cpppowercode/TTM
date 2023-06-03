#pragma once
class Cannon : public Actor
{
public:
    static Cannon* Create(string name = "Cannon");

    //������ ���� calculateŬ������ �̵��ؾ���
    //���� ���� ��

    class MainUI* mainUI;
    class Player* player;
    Vector3 Direction;
    float Gauge;
private:
    Cannon();
    virtual ~Cannon();
    
    
public:
    void	Update() override;
    void	Release() override;
    
    void    cannonCharge();
    void    cannonShot();
    void    dissipation();
};

