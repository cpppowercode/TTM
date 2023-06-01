#pragma once
class ObjectPool : Actor
{
public:
    ObjectPool();
    ~ObjectPool();

    Airplane* airPlane;
    Airplane* GetAirplane();
    static vector<Airplane*> AirplaneCreate(string name = "Airplane");

    void	Release() override;
private:
    vector<Airplane*> airplanePool;
};

