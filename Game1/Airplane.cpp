#include "stdafx.h"
#include "Airplane.h"
#include "Player.h"

Airplane* Airplane::Create(string name)
{
	Airplane* airPlane = new Airplane();
	airPlane->LoadFile("Airplane.xml");
	airPlane->isInUse = true;

	airPlane->player = Player::Create();
	airPlane->name = name;


	float tempX = RANDOM->Float(-500.0f, 500.0f);
	float tempY = RANDOM->Float(-500.0f, 500.0f);
	float tempZ = RANDOM->Float(20.0f, 500.0f);

	bool Opposite = RANDOM->Int(0, 1);

	Vector3 tempPos = airPlane->player->GetWorldPos() +
		Vector3(tempX, tempY, tempZ);

	airPlane->SetWorldPos(tempPos);




	if (tempPos.y < 0) airPlane->SetWorldPos(tempPos + Vector3(0, 500, 0));
	if (Opposite) airPlane->rotation.y = 180 * TORADIAN;

	//cout << tempPos.y << endl;

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

	// SetWorldPosX(GetWorldPos().x + -50 * DELTA);

	MoveWorldPos(-GetRight() * DELTA * 50);


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
