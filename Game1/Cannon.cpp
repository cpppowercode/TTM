#include "stdafx.h"
#include "Cannon.h"
#include "Player.h"
#include "MainUI.h"

Cannon* Cannon::Create(string name)
{
	Cannon* cannon = new Cannon();
	cannon->LoadFile("Cannon1.xml");

	cannon->mainUI = MainUI::Create();

	//대포 생성시 초기화
	Vector3(Direction) = Vector3(0, 0, 0);
	//게이지 초기화
	float Gauge = 0.0f;

	return cannon;
}

Cannon::Cannon()
{
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{	
	//대포 각도 조정
	if (INPUT->KeyPress(VK_UP)&& Find("cannonJoint")->rotation.x>-1.5f&&player->IsFire == false)
	{
		if (Find("cannonJoint"))
		{
			Find("cannonJoint")->rotation.x += DELTA * -3.14;
		}

	}
	if (INPUT->KeyPress(VK_DOWN) && Find("cannonJoint")->rotation.x < 0 && player->IsFire == false)
	{
		if (Find("cannonJoint"))
		{
			Find("cannonJoint")->rotation.x += DELTA * 3.14;
		}
	}

	//cout << Find("cannonJoint")->rotation.x << endl;

	if (player->IsFire == false)
	{
		player->visible = false;
		player->SetPlayerWorldPos(Find("playerpoint")->GetWorldPos());
		player->SetPlayerRotationX(-(Find("cannonJoint")->rotation.x + (90 * TORADIAN)));
	}
	//cannon GetForward()값
	Direction = Find("GunBarrel")->GetForward();


	Actor::Update();
}

void Cannon::Release()
{
	for (auto it = children.begin(); it != children.end(); it++)
	{
		SafeRelease(it->second);
	}
	delete this;
}

void Cannon::cannonCharge()
{
	if (mainUI->botton->Find("playbotton")->visible == false && INPUT->KeyPress(VK_SPACE))
	{
		mainUI->gaugefront->Find("GaugeFront")->scale.y = Util::Saturate(mainUI->gaugefront->Find("GaugeFront")->scale.y, 0.0f, 0.77f);
		if (mainUI->gaugefront->Find("GaugeFront")->scale.y == 0.77f)
		{
			mainUI->gaugefront->Find("GaugeFront")->scale.y = 0.0f;
		}
		else if (mainUI->gaugefront->Find("GaugeFront")->scale.y < 0.4f)
		{
			mainUI->gaugefront->Find("GaugeFront")->scale.y += 0.5f * DELTA;
		}
		else if (mainUI->gaugefront->Find("GaugeFront")->scale.y > 0.4f)
		{
			mainUI->gaugefront->Find("GaugeFront")->scale.y += 3.0f * DELTA;
		}
		else if (mainUI->gaugefront->Find("GaugeFront")->scale.y > 0.68f)
		{
			mainUI->gaugefront->Find("GaugeFront")->scale.y += 7.0f * DELTA;
		}
		Gauge += (mainUI->gaugefront->Find("GaugeFront")->scale.y * 200.0f) * DELTA;
	}
}

void Cannon::cannonShot()
{
	if (mainUI->botton->Find("playbotton")->visible == false && INPUT->KeyUp(VK_SPACE))
	{
		mainUI->gaugefront->Find("GaugeFront")->visible = false;
		mainUI->gauge->Find("Gauge")->visible = false;
		mainUI->gaugeback->Find("GaugeBack")->visible = false;
		player->visible = true;

		player->scalar = Gauge;
		player->seta = Direction;
		player->SetVelocity();
		player->IsFire = true;
		player->gravity = 10.0f;
		Camera::main = (Camera*)player->Find("BackCam");
	}
}

void Cannon::dissipation()
{
	if (player->IsFire == false)
	{
		player->visible = false;
		player->SetPlayerWorldPos(Find("cannonJoint")->GetWorldPos());
		player->SetPlayerRotationX(-(Find("cannonJoint")->rotation.x + (90 * TORADIAN)));
	}
}
