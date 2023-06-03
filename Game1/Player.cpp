#include "stdafx.h"
#include "Cannon.h"
#include "Airplane.h"
#include "ObjectPool.h"
#include "MainUI.h"
#include "Player.h"

Player* Player::Create(string name)
{
	Player* player = new Player();
	player->LoadFile("TTMtest.xml");

	
	player->Ani[0] = Actor::Create();
	player->Ani[0]->LoadFile("TTMtest.xml");
	player->Ani[0]->Update();

	player->Ani[1] = Actor::Create();
	player->Ani[1]->LoadFile("TTMAni1.xml");
	player->Ani[1]->Update();

	player->Ani[2] = Actor::Create();
	player->Ani[2]->LoadFile("TTMAni2.xml");
	player->Ani[2]->Update();

	player->Ani[3] = Actor::Create();
	player->Ani[3]->LoadFile("TTMAni3.xml");
	player->Ani[3]->Update();
	
  
	player->IsFire = false;
	player->gravity = 0.0f;
	player->scalar = 0.0f;
	player->BoosterScalar = 1.0f;
	player->src = 0;
	player->dest = 0;
	player->t = 1.0f;
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

void Player::SetVelocity()
{
	//Vector3 Direction = Vector3(cannon->Direction.x * scalar, cannon->Direction.y * scalar , cannon->Direction.z *scalar);
	velocity = (cannon->Direction * scalar) - (UP * gravity);
}

void Player::MovePlayer()
{
	// ZY 평면에서의 벡터값에 중력 뺀 방향으로 이동시키는 함수인데 의미가 있나...?
	if (IsFire)
	{
		Find(root->name)->MoveWorldPos((velocity) * BoosterScalar * DELTA);
		for (int i = 0; i < 4; i++)
		{
			Ani[i]->MoveWorldPos((velocity) * BoosterScalar * DELTA);
		}
		gravity += 10 * DELTA;
	}
}

void Player::PlayerAnimationPosSetting(Actor* Animation, int size)
{
	// 애니메이션 부르기 전에 기존에 불러왔던 xml들 초기 위치를 플레이어 위치로 이동시킴
	
}

// 수업시간에 쓴 애니메이션 함수 복붙
void Player::Animation(GameObject* root)
{
	GameObject* _src = Ani[src]->Find(root->name);
	GameObject* _dest = Ani[dest]->Find(root->name);	
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

}

void Player::ChangeAni()
{
	// 밑의 주석은 애니메이션 변경 실험용임. 
	t = 0;
	if (dest == 3)
	{
		dest = 0;
	}
	else
	{
		dest++;
	}	
}


Vector3 Player::GetPlayerWorldPos()
{
	
	
	return GetWorldPos();
}

void Player::SetPlayerWorldPos(Vector3 pos)
{
	SetWorldPos(pos);
}

void Player::SetPlayerRotationX(float rot)
{
	GameObject* Rot = Find("HoleBone");
	Rot->rotation.x = rot;
}



void Player::SetPlayerRotationY(float rot)
{
	GameObject* Rot = Find("HoleBone");
	Rot->rotation.y = rot;
}

void Player::SetPlayerRotationZ(float rot)
{
	GameObject* Rot = Find("HoleBone");
	Rot->rotation.z = rot;
}

float Player::GetPlayerRotationX()
{
	GameObject* Rot = Find("HoleBone");
	return Rot->rotation.x;
}

float Player::GetPlayerRotationY()
{
	GameObject* Rot = Find("HoleBone");
	return Rot->rotation.y;
}

float Player::GetPlayerRotationZ()
{
	GameObject* Rot = Find("HoleBone");
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
	if (t < 1.0f)
	{

		Animation(Find(root->name));



		t += DELTA;
		if (t >= 1.0f)
		{
			t = 1.0f;
			src = dest;
		}
	}

	if (IsFire)
	{
		MovePlayer();
		SetVelocity();
		Find("HoleBone")->rotation.x = (atan2f(velocity.y, velocity.z) + (-90 * TORADIAN));
		for (int i = 0; i < 4; i++)
		{
			Ani[i]->Find("HoleBone")->rotation.x = Find("HoleBone")->rotation.x;
		}
	}

	Actor::Update();
}




