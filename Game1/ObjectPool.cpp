#include "stdafx.h"
#include "Airplane.h"
#include "ObjectPool.h"

#define INITIAL_POOL_SIZE 100

vector<Airplane*> ObjectPool::AirplaneCreate(string name)
{
    Airplane* airPlane;
    vector<Airplane*> airplanePool;
    for (int i = 0; i < INITIAL_POOL_SIZE; i++)
    {
        string name = "airplane";
        name += to_string(i);
        airPlane = Airplane::Create(name);
        airplanePool.push_back(airPlane);
    }

    return airplanePool;
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
            // airPlane->Reset();
            return airPlane;
        }
    }

    Airplane* newAirplane = Airplane::Create();
    airplanePool.push_back(newAirplane);
    return newAirplane;
}

void ObjectPool::Release()
{
    //for (Airplane* airplane : airplanePool)
    //{
    //    airplane->isInUse = false;
    //    // airplane->Reset();
    //
    //    airPlane->Release();
    //}
    //airplanePool.clear();
}