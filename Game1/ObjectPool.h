#pragma once
class ObjectPool : Actor
{
public:
    ObjectPool();
    ~ObjectPool();

    Airplane* airPlane;
    Airplane* GetAirplane();

    void	Release() override;
private:
    vector<Airplane*> airplanePool;
};

