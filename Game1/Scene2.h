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
	//대포 클래스생성
	Cannon* cannon;


	vector<Airplane*> airplanes;
	vector<Malphite*> malphites;
public:
	Scene2();
	~Scene2();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void PreRender() override;
	virtual void ResizeScreen() override;


};

