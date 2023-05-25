#pragma once
class Airplane : public Actor
{
public:
    static Airplane* Create(string name = "Airplane");

    bool isInUse;
private:
    Airplane();
    virtual ~Airplane();

public:
    void	Update() override;
    void	Release() override;
};

