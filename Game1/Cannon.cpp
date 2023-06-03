#include "stdafx.h"
#include "Cannon.h"

Cannon* Cannon::Create(string name)
{
	Cannon* cannon = new Cannon();
	cannon->LoadFile("Cannon1.xml");

	

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
	if (INPUT->KeyPress(VK_UP))
	{
		if (Find("cannonJoint"))
		{
			Find("cannonJoint")->rotation.x += DELTA * -3.14;
		}

	}
	if (INPUT->KeyPress(VK_DOWN))
	{
		if (Find("cannonJoint"))
		{
			Find("cannonJoint")->rotation.x += DELTA * 3.14;
		}
	}

	//cannon GetForward()값
	Direction = Find("GunBarrel")->GetForward();
	/*cout << Direction.x << endl;
	cout << Direction.y << endl;
	cout << Direction.z << endl;*/

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
