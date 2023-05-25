#pragma once
class Cannon : public Actor
{
public:
    static Cannon* Create(string name = "Cannon");
private:
    Cannon();
    virtual ~Cannon();

public:
    void	Update() override;
    void	Release() override;
};

