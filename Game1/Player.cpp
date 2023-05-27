#include "stdafx.h"
#include "Player.h"

Player* Player::Create(string name)
{
	Player* player = new Player();
	player->LoadFile("TossMan.xml");



	return player;
}

void Player::Release()
{
	for (auto it = children.begin(); it != children.end(); it++)
	{
		SafeRelease(it->second);
	}
	delete this;
}

Vector3 Player::GetPlayerWorldPos()
{
	GameObject* Pos = Find("TossMan");
	
	return Pos->GetWorldPos();
}

void Player::SetPlayerWorldPos(Vector3 pos)
{
	GameObject* Pos = Find("TossMan");
	Pos->SetWorldPos(pos);
}

void Player::SetPlayerRotationX(float rot)
{
	GameObject* Rot = Find("TossMan");
	Rot->rotation.x = rot;
}

void Player::SetPlayerRotationY(float rot)
{
	GameObject* Rot = Find("TossMan");
	Rot->rotation.y = rot;
}

void Player::SetPlayerRotationZ(float rot)
{
	GameObject* Rot = Find("TossMan");
	Rot->rotation.z = rot;
}

float Player::GetPlayerRotationX()
{
	GameObject* Rot = Find("TossMan");
	return Rot->rotation.x;
}

float Player::GetPlayerRotationY()
{
	GameObject* Rot = Find("TossMan");
	return Rot->rotation.y;
}

float Player::GetPlayerRotationZ()
{
	GameObject* Rot = Find("TossMan");
	return Rot->rotation.z;
}

Player::Player()
{
}

Player::~Player()
{
}

void Player::Update()
{
	Actor::Update();
}


