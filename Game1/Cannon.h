#pragma once
class Cannon : public Actor
{
public:
    static Cannon* Create(string name = "Cannon");
private:
    Cannon();
    virtual ~Cannon();
    
    
    //변수는 추후 calculate클래스로 이동해야함
    //대포 각도 값
    Vector3 Direction;
    //대포 게이지
    float Gauge;
public:
    void	Update() override;
    void	Release() override;
};

