#pragma once
#include "Airplane.h"
#include "ObjectPool.h"
#include "Player.h"
#include "Cannon.h"

class Scene2 : public Scene
{
private:
	Camera* Cam;
	Grid*	grid;
	Player* player;
	//���� Ŭ��������
	Cannon* cannon;

	UI* open;
	UI* botton;
	UI* booster;
	UI* bomb;
	UI* gun;
	UI* reload;
	UI* bullet;
	UI* bullet2;
	UI* bullet3;
	UI* bullet4;
	UI* bullet5;
	UI* stop;
	UI* option;
	UI* continueUI;
	UI* retry;

	vector<Airplane*> airplanes;
public:
	Scene2();
	~Scene2();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void PreRender() override;
	virtual void ResizeScreen() override;


};

