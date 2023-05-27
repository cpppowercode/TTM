#include "stdafx.h"
#include "Airplane.h"

Airplane* Airplane::Create(string name)
{
	Airplane* airPlane = new Airplane();

	airPlane->isInUse = true;
	return airPlane;
}

Airplane::Airplane()
{
}

Airplane::~Airplane()
{
}

void Airplane::Update()
{
	Actor::Update();
}

void Airplane::Release()
{
	for (auto it = children.begin(); it != children.end(); it++)
	{
		SafeRelease(it->second);
	}
	delete this;
}
