#include "stdafx.h"
#include "Malphite.h"

Malphite* Malphite::Create(string name)
{
	Malphite* malphite = new Malphite();
	malphite->LoadFile("Malphite.xml");
	malphite->isInUse = true;

	malphite->player = Player::Create();
	malphite->name = name;

	float randomSeed = Camera::main->farZ;

	float tempX = RANDOM->Float(-randomSeed, randomSeed);
	float tempY = RANDOM->Float(-randomSeed, randomSeed);
	float tempZ = RANDOM->Float(20.0f, randomSeed);

	bool Opposite = RANDOM->Int(0, 1);

	Vector3 tempPos = malphite->player->GetWorldPos() +
		Vector3(tempX, tempY, tempZ);

	malphite->SetWorldPos(tempPos);

	if (tempPos.y < 0) malphite->SetWorldPos(tempPos + Vector3(0, 500, 0));
	if (Opposite) malphite->rotation.y = 180 * TORADIAN;

	return malphite;

	return nullptr;
}

Malphite::Malphite()
{
}

Malphite::~Malphite()
{
}

void Malphite::Update()
{
}

void Malphite::LateUpdate()
{
}

void Malphite::Release()
{
}

void Malphite::Reset()
{
}
