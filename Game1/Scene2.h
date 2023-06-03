#pragma once
#include "Calculate.h"
#include "Airplane.h"
#include "ObjectPool.h"
#include "Player.h"
#include "Cannon.h"
#include "MainUI.h"


class Scene2 : public Scene
{
private:
	Camera* Cam;
	Grid*	grid;
	Player* player;
	MainUI* mainUI;
	//���� Ŭ��������
	Cannon* cannon;


	vector<Airplane*> airplanes;
	vector<Malphite*> malphites;
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

