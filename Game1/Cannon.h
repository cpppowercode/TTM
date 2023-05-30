#pragma once
class Cannon : public Actor
{
public:
    static Cannon* Create(string name = "Cannon");
private:
    Cannon();
    virtual ~Cannon();
    
    
    //������ ���� calculateŬ������ �̵��ؾ���
    //���� ���� ��
    Vector3 Direction;
    //���� ������
    float Gauge;
public:
    void	Update() override;
    void	Release() override;
};

