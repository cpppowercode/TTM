#include "stdafx.h"
#include "ObjectPool.h"

#define AIRPLANE_INITIAL_POOL_SIZE 100
#define MALPHITE_INITIAL_POOL_SIZE 30

vector<Airplane*> ObjectPool::AirplaneCreate(string name)
{
    Airplane* airPlane;
    vector<Airplane*> airplanePool;
    for (int i = 0; i < AIRPLANE_INITIAL_POOL_SIZE; i++)
    {
        string name = "airplane";
        name += to_string(i);
        airPlane = Airplane::Create(name);
        airplanePool.push_back(airPlane);
    }

    return airplanePool;
}

vector<Malphite*> ObjectPool::MalphiteCreate(string name)
{
    Malphite* malphite;
    vector<Malphite*> malphitePool;
    for (int i = 0; i < MALPHITE_INITIAL_POOL_SIZE; i++)
    {
        string name = "malphite";
        name += to_string(i);
        malphite = Malphite::Create(name);
        malphitePool.push_back(malphite);
    }

    return malphitePool;
}

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}

Airplane* ObjectPool::GetAirplane()
{
    for (Airplane* airPlane : airplanePool)
    {
        if (!airPlane->isInUse)
        {
            airPlane->Reset();
            return airPlane;
        }
    }

    Airplane* newAirplane = Airplane::Create();
    airplanePool.push_back(newAirplane);
    return newAirplane;
}

Malphite* ObjectPool::GetMalphite()
{
    for (Malphite* malphite : malphitePool)
    {
        if (!malphite->isInUse)
        {
            malphite->Reset();
            return malphite;
        }
    }

    Malphite* newMalphite = Malphite::Create();
    malphitePool.push_back(newMalphite);
    return newMalphite;
}

void ObjectPool::Release()
{
}