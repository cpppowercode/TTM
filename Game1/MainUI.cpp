#include "stdafx.h"
#include "MainUI.h"

MainUI* MainUI::Create(string name)
{
	MainUI* mainui = new MainUI();
	mainui->LoadFile("");



	return mainui;
}

void MainUI::Release()
{
	for (auto it = children.begin(); it != children.end(); it++)
	{
		SafeRelease(it->second);
	}
	delete this;
}

MainUI::MainUI()
{
}

MainUI::~MainUI()
{
}

void MainUI::Update()
{
	Actor::Update();
}


