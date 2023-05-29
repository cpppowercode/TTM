#include "stdafx.h"
#include "Airplane.h"
#include "Player.h"

Airplane* Airplane::Create(string name)
{
	Airplane* airPlane = new Airplane();
	airPlane->isInUse = true;

	airPlane->player = Player::Create();
	airPlane->name = name;
	Vector3 tempPos = airPlane->player->GetWorldPos() + Vector3((RANDOM->Float(0.0f, 10.0f),RANDOM->Float(0.0f, 10.0f), RANDOM->Float(0.0f, 10.0f)));

	airPlane->SetWorldPos(tempPos);

	airPlane->player->GetLocalPos();

	cout << airPlane->player->GetWorldPos().x << endl;

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
