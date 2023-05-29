#pragma once
#include "Airplane.h"
#include "ObjectPool.h"
#include "Player.h"

class Scene2 : public Scene
{
private:
	Camera* Cam;
	Grid*	grid;
	Player* player;

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

	vector<Airplane*> objects;
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

