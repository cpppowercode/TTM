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

	float randomSeed = Camera::main->farZ / 10.0f;

	cout << randomSeed << endl;

	float tempX = RANDOM->Float(-randomSeed, randomSeed);
	float tempY = RANDOM->Float(-randomSeed, randomSeed);
	float tempZ = RANDOM->Float(20.0f, randomSeed);

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


	if (GetWorldPos().z - player->GetWorldPos().z < Camera::main->nearZ)
	{
		Reset();
	}

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

void Airplane::Reset()
{
	float randomSeed = Camera::main->farZ / 10.0f;

	float tempX = RANDOM->Float(-500, 500);
	float tempY = RANDOM->Float(-500, 500);
	float tempZ = RANDOM->Float(20.0f, 500);
	
	//bool Opposite = RANDOM->Int(0, 1);
	
	Vector3 tempPos = player->GetWorldPos() +
		Vector3(tempX, tempY, tempZ);
	
	SetWorldPos(tempPos);
	
	if (tempPos.y < 0) SetWorldPos(tempPos + Vector3(0, 500, 0));
	 //if (Opposite) rotation.y = 180 * TORADIAN;
}
