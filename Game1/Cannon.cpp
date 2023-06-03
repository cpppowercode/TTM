#include "stdafx.h"
#include "Cannon.h"

Cannon* Cannon::Create(string name)
{
	Cannon* cannon = new Cannon();
	cannon->LoadFile("Cannon1.xml");

	

	//���� ������ �ʱ�ȭ
	Vector3(Direction) = Vector3(0, 0, 0);
	//������ �ʱ�ȭ
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
	//���� ���� ����
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

	//cannon GetForward()��
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
