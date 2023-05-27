#pragma once
#include "Airplane.h"
#include "ObjectPool.h"

class Scene2 : public Scene
{
private:
	Camera* Cam;
	Grid*	grid;
	vector<Airplane*> objects;
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

