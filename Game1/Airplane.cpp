#include "stdafx.h"
#include "Airplane.h"

Airplane* Airplane::Create(string name)
{
	Airplane* airPlane = new Airplane();
	airPlane->LoadFile("Airplane.xml");
	airPlane->isInUse = true;

	airPlane->player = Player::Create();
	airPlane->name = name;

	float randomSeed = Camera::main->farZ;

	float tempX = RANDOM->Float(-randomSeed, randomSeed);
	float tempY = RANDOM->Float(-randomSeed, randomSeed);
	float tempZ = RANDOM->Float(20.0f, randomSeed);

	bool Opposite = RANDOM->Int(0, 1);

	Vector3 tempPos = airPlane->player->GetWorldPos() +
		Vector3(tempX, tempY, tempZ);

	airPlane->SetWorldPos(tempPos);

	if (tempPos.y < 0) airPlane->SetWorldPos(tempPos + Vector3(0, 500, 0));
	if (Opposite) airPlane->rotation.y = 180 * TORADIAN;

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
	double camFar = Camera::main->farZ;


	if (GetWorldPos().z < player->GetWorldPos().z ||
		GetWorldPos().x - player->GetWorldPos().x < -camFar ||
		GetWorldPos().x - player->GetWorldPos().x >  camFar)
	{
		Reset();
	}
	
		
	Actor::Update();
}

void Airplane::LateUpdate()
{
	if (Intersect(player))
	{
		if (GetWorldPos().y > player->GetWorldPos().y)
		{

		}

		if (GetWorldPos().y < player->GetWorldPos().y)
		{

		}
	}
}

void Airplane::Release()
{
	for (auto it = children.begin(); it != children.end(); it++)
	{
		SafeRelease(it->second);
	}
	delete this;
}

void Airplane::Reset()
{
	float randomSeed = Camera::main->farZ;

	float tempX = RANDOM->Float(-randomSeed, randomSeed);
	float tempY = RANDOM->Float(-randomSeed, randomSeed);
	float tempZ = RANDOM->Float(20.0f, randomSeed * 2);

	//bool Opposite = RANDOM->Int(0, 1);

	Vector3 tempPos = player->GetWorldPos() +
		Vector3(tempX, tempY, tempZ);

	SetWorldPos(tempPos);

	if (tempPos.y < 0) SetWorldPos(tempPos + Vector3(0, 500, 0));
	//if (Opposite) rotation.y = 180 * TORADIAN;
}
