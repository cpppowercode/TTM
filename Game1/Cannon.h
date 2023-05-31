#pragma once
class Cannon : public Actor
{
public:
    static Cannon* Create(string name = "Cannon");

    //변수는 추후 calculate클래스로 이동해야함
    //대포 각도 값
    Vector3 Direction;
    //대포 게이지
    float Gauge;
private:
    Cannon();
    virtual ~Cannon();
    
    
public:
    void	Update() override;
    void	Release() override;
};

