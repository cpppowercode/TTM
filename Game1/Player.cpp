#include "stdafx.h"
#include "Player.h"

Player* Player::Create(string name)
{
	Player* player = new Player();
	player->LoadFile("");



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


