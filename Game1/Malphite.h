#include "Airplane.h"
#include "Player.h"

#pragma once
class Malphite : public Actor
{
public:
    static Malphite* Create(string name = "Airplane");
    class Player* player;
    bool isInUse;
private:
    Malphite();
    virtual ~Malphite();

public:
    void	Update() override;
    void	LateUpdate();
    void	Release() override;
    void    Reset();
};

