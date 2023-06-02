#include "Player.h"

#pragma once
class Airplane : public Actor
{
public:
    static Airplane* Create(string name = "Airplane");
    class Player* player;
    bool isInUse;
private:
    Airplane();
    virtual ~Airplane();

public:
    void	Update() override;
    void	LateUpdate();
    void	Release() override;
    void    Reset();
};

