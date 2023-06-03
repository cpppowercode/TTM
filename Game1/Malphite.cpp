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

	malphite->Opposite = RANDOM->Int(0, 1);

	Vector3 tempPos = malphite->player->GetWorldPos() +
		Vector3(tempX, tempY, tempZ);

	malphite->SetWorldPos(tempPos);

	if (tempPos.y < 0) malphite->SetWorldPos(tempPos + Vector3(0, 500, 0));
	if (malphite->Opposite) malphite->rotation.y = 180 * TORADIAN;

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
	MoveWorldPos(-GetRight() * DELTA * 50);
	double camFar = Camera::main->farZ;


	if (GetWorldPos().z < player->GetWorldPos().z ||
		GetWorldPos().x - player->GetWorldPos().x < -camFar ||
		GetWorldPos().x - player->GetWorldPos().x >  camFar)
		Reset();

	Actor::Update();
}

void Malphite::LateUpdate()
{
	if (Intersect(player->Find("Body")))
	{
		player->rotation.x = -player->rotation.x;
		player->ChangeAni();
	}
}

void Malphite::Release()
{
	for (auto it = children.begin(); it != children.end(); it++)
	{
		SafeRelease(it->second);
	}
	delete this;
}

void Malphite::Reset()
{
	float randomSeed = Camera::main->farZ;
	float tempX = 0;
	if (Opposite)  tempX = -randomSeed;
	if (!Opposite) tempX = randomSeed;

	float tempY = RANDOM->Float(-randomSeed, randomSeed);
	float tempZ = RANDOM->Float(20.0f, randomSeed * 2);

	Vector3 tempPos = player->GetWorldPos() +
		Vector3(tempX, tempY, tempZ);

	SetWorldPos(tempPos);

	if (tempPos.y < 0) SetWorldPos(tempPos + Vector3(0, 500, 0));
}
