#include "Airplane.h"
#include "Malphite.h"

#pragma once
class ObjectPool : Actor
{
public:
    ObjectPool();
    ~ObjectPool();

    Airplane* airPlane;
    Airplane* GetAirplane();
    Malphite* GetMalphite();

    static vector<Airplane*> AirplaneCreate(string name = "Airplane");
    static vector<Malphite*> MalphiteCreate(string name = "Malphite");
    
    int     objLev = 0;
    void	Release() override;
private:
    vector<Airplane*> airplanePool;
    vector<Malphite*> malphitePool;
};

