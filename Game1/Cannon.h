#pragma once
class Cannon : public Actor
{
public:
    static Cannon* Create(string name = "Cannon");

    //변수는 추후 calculate클래스로 이동해야함
    //대포 각도 값

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

