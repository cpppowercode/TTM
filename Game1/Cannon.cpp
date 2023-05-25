#include "stdafx.h"
#include "Cannon.h"

Cannon* Cannon::Create(string name)
{
	Cannon* cannon = new Cannon();
	cannon->LoadFile("cannon.xml");

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
	if (INPUT->KeyPress(VK_UP))
	{
		if (Find("GunBarrel"))
		{
			rotation.y += DELTA * 3.14;
		}

	}
	if (INPUT->KeyPress(VK_DOWN))
	{

	}

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
