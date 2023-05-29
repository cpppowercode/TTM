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

void Player::MovePlayer(float scalar, float seta)
{
	// ZY ��鿡���� ���Ͱ��� �߷� �� �������� �̵���Ű�� �Լ��ε� �ǹ̰� �ֳ�...?
	Find("root")->MoveWorldPos(((Vector3(0.0f, sin(seta), cos(seta)) * scalar * DELTA) + (-UP * gravity) * DELTA) + (ObbColPos * DELTA));
}

void Player::PlayerAnimationPosSetting(Actor* Animation, int size)
{
	// �ִϸ��̼� �θ��� ���� ������ �ҷ��Դ� xml�� �ʱ� ��ġ�� �÷��̾� ��ġ�� �̵���Ŵ
	for (int i = 0; i < size; i++)
	{
		Animation[size].SetWorldPos(Find(root->name)->GetWorldPos());
	}
}

// �����ð��� �� �ִϸ��̼� �Լ� ����
void Player::Animation(GameObject* root)
{
	GameObject* _src = Ani[src].Find(root->name);
	GameObject* _dest = Ani[dest].Find(root->name);
	Vector3 CurrentPos = _src->GetWorldPos();
	root->SetLocalPos(Util::Lerp(_src->GetLocalPos(),
		_dest->GetLocalPos(), t));
	//root->rotation =
	//Util::QuaternionToYawPtichRoll(
	//    Util::Lerp(
	//        Quaternion::CreateFromYawPitchRoll(_src->rotation.y, _src->rotation.x, _src->rotation.z),
	//        Quaternion::CreateFromYawPitchRoll(_dest->rotation.y, _dest->rotation.x, _dest->rotation.z)
	//        , t));

	root->rotation = Util::Lerp(_src->rotation, _dest->rotation, t);

	for (auto it = root->children.begin();
		it != root->children.end(); it++)
	{
		Animation(it->second);
	}

	_dest->SetWorldPos(CurrentPos);
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


