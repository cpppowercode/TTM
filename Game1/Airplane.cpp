#include "stdafx.h"
#include "Airplane.h"
#include "Player.h"

Airplane* Airplane::Create(string name)
{
	Airplane* airPlane = new Airplane();

	airPlane->isInUse = true;

	airPlane->player = Player::Create();

	airPlane->SetWorldPos(airPlane->player->GetWorldPos() +
		Vector3(RANDOM->Float(1.1f, 1.15f),
			RANDOM->Float(1.1f, 1.15f),
			RANDOM->Float(1.1f, 1.15f)));


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
