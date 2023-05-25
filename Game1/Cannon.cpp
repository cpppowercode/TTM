#include "stdafx.h"
#include "Cannon.h"

Cannon* Cannon::Create(string name)
{
	Cannon* cannon = new Cannon();
	

	return cannon;
}

Cannon::Cannon()
{
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	Actor::Update();
}

void Cannon::Release()
{
	for (auto it = children.begin(); it != children.end(); it++)
	{
		SafeRelease(it->second);
	}
	delete this;
}
