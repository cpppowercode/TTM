#include "stdafx.h"
#include "MainUI.h"

MainUI* MainUI::Create(string name)
{
	MainUI* mainui = new MainUI();
	

    ///UI 시작화면
    mainui->open = UI::Create();
    mainui->open->LoadFile("OpenUI.xml");

    mainui->botton = UI::Create();
    mainui->botton->LoadFile("OpenBottonUI.xml");

    //ITEM UI
    mainui->booster = UI::Create();
    mainui->booster->LoadFile("BoosterUI.xml");

    mainui->bomb = UI::Create();
    mainui->bomb->LoadFile("BombUI.xml");

    mainui->reload = UI::Create();
    mainui->reload->LoadFile("ReloadUI.xml");

    mainui->gun = UI::Create();
    mainui->gun->LoadFile("GunUI.xml");

    mainui->bullet = UI::Create();
    mainui->bullet->LoadFile("BulletUI.xml");

    mainui->bullet2 = UI::Create();
    mainui->bullet2->LoadFile("BulletUI2.xml");

    mainui->bullet3 = UI::Create();
    mainui->bullet3->LoadFile("BulletUI3.xml");

    mainui->bullet4 = UI::Create();
    mainui->bullet4->LoadFile("BulletUI4.xml");

    mainui->bullet5 = UI::Create();
    mainui->bullet5->LoadFile("BulletUI5.xml");

    //Option UI
    mainui->stop = UI::Create();
    mainui->stop->LoadFile("StopUI.xml");

    mainui->option = UI::Create();
    mainui->option->LoadFile("OptionUI.xml");

    mainui->continueUI = UI::Create();
    mainui->continueUI->LoadFile("ContinueUI.xml");

    mainui->retry = UI::Create();
    mainui->retry->LoadFile("RetryUI.xml");

    //Gauge UI
    mainui->gauge = UI::Create();
    mainui->gauge->LoadFile("GaugeUI.xml");

    mainui->gaugefront = UI::Create();
    mainui->gaugefront->LoadFile("GaugeFrontUI.xml");

    mainui->gaugeback = UI::Create();
    mainui->gaugeback->LoadFile("GaugeBackUI.xml");


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
    //UI
    open->RenderHierarchy();
    botton->RenderHierarchy();
    booster->RenderHierarchy();
    bomb->RenderHierarchy();
    reload->RenderHierarchy();
    gun->RenderHierarchy();
    bullet->RenderHierarchy();
    bullet2->RenderHierarchy();
    bullet3->RenderHierarchy();
    bullet4->RenderHierarchy();
    bullet5->RenderHierarchy();
    stop->RenderHierarchy();
    option->RenderHierarchy();
    continueUI->RenderHierarchy();
    retry->RenderHierarchy();
    gauge->RenderHierarchy();
    gaugefront->RenderHierarchy();
    gaugeback->RenderHierarchy();

    //UI 시작화면
    if (botton->MouseOver())
    {
        botton->Find("playbotton")->scale.x = RANDOM->Float(1.1f, 1.15f);
        botton->Find("playbotton")->scale.y = RANDOM->Float(1.0f, 1.05f);

        if (open->Find("TTM")->visible == true && INPUT->KeyDown(VK_LBUTTON))
        {
            open->Find("TTM")->visible = false;
            botton->Find("playbotton")->visible = false;
        }
    }
    else
    {
        botton->Find("playbotton")->scale.x = 1.1f;
        botton->Find("playbotton")->scale.y = 1.0f;
    }
    //UI 1번버튼 부스터
    if (booster->MouseOver())
    {
        booster->Find("boosterON")->scale.x = RANDOM->Float(2.0f, 2.2f);
        booster->Find("boosterON")->scale.y = RANDOM->Float(2.6f, 2.8f);


        if (booster->Find("boosterON")->visible == true && INPUT->KeyDown(VK_LBUTTON))
        {
            booster->Find("boosterON")->visible = false;
        }

    }
    else
    {
        booster->Find("boosterON")->scale.x = 2.0f;
        booster->Find("boosterON")->scale.y = 2.6f;
        if (booster->Find("boosterON")->visible == false)
        {
            booster->Find("boosterOFF")->visible = true;
        }
    }
    //UI 2번버튼 폭탄
    if (bomb->MouseOver())
    {
        bomb->Find("bombON")->scale.x = RANDOM->Float(2.0f, 2.2f);
        bomb->Find("bombON")->scale.y = RANDOM->Float(2.6f, 2.8f);


        if (bomb->Find("bombON")->visible == true && INPUT->KeyDown(VK_LBUTTON))
        {
            App.deltaScale = 1.0f;
            bomb->Find("bombON")->visible = false;
        }

    }
    else
    {
        bomb->Find("bombON")->scale.x = 2.0f;
        bomb->Find("bombON")->scale.y = 2.6f;
        if (bomb->Find("bombON")->visible == false)
        {
            bomb->Find("bombOFF")->visible = true;
        }
    }
    //UI 3번버튼 재장전
    if (reload->MouseOver())
    {
        reload->Find("reloadON")->scale.x = RANDOM->Float(2.0f, 2.2f);
        reload->Find("reloadON")->scale.y = RANDOM->Float(2.6f, 2.8f);

        if (reload->Find("reloadON")->visible == true && INPUT->KeyDown(VK_LBUTTON))
        {
            App.deltaScale = 0.0f;
            reload->Find("reloadON")->visible = false;
        }
    }
    else
    {
        reload->Find("reloadON")->scale.x = 2.0f;
        reload->Find("reloadON")->scale.y = 2.6f;
        if (reload->Find("reloadON")->visible == false)
        {
            reload->Find("reloadOFF")->visible = true;
        }
    }
    //UI 일시정지버튼
    if (stop->MouseOver())
    {
        stop->Find("stop")->scale.x = RANDOM->Float(1.15f, 1.2f);
        stop->Find("stop")->scale.y = RANDOM->Float(1.15f, 1.2f);

        if (option->Find("option")->visible == false && INPUT->KeyDown(VK_LBUTTON))
        {
            App.deltaScale = 0.0f;
            option->Find("option")->visible = true;
            continueUI->Find("continue")->visible = true;
            retry->Find("retry")->visible = true;
        }
    }
    else
    {
        stop->Find("stop")->scale.x = 1.15f;
        stop->Find("stop")->scale.y = 1.15f;
    }
    //UI 이어하기버튼
    if (continueUI->MouseOver())
    {
        continueUI->Find("continue")->scale.x = RANDOM->Float(1.0f, 1.05f);
        continueUI->Find("continue")->scale.y = RANDOM->Float(1.0f, 1.05f);

        if (option->Find("option")->visible == true && INPUT->KeyDown(VK_LBUTTON))
        {
            App.deltaScale = 1.0f;
            option->Find("option")->visible = false;
            continueUI->Find("continue")->visible = false;
            retry->Find("retry")->visible = false;
        }
    }
    else
    {
        continueUI->Find("continue")->scale.x = 1.0f;
        continueUI->Find("continue")->scale.y = 1.0f;
    }
    //UI 다시하기버튼
    if (retry->MouseOver())
    {
        retry->Find("retry")->scale.x = RANDOM->Float(1.0f, 1.05f);
        retry->Find("retry")->scale.y = RANDOM->Float(1.0f, 1.05f);

        /*if (retry->Find("retry")->visible == true && INPUT->KeyDown(VK_LBUTTON))
        {

        }*/
    }
    else
    {
        retry->Find("retry")->scale.x = 1.0f;
        retry->Find("retry")->scale.y = 1.0f;
    }


    //UI
    open->Update();
    botton->Update();
    booster->Update();
    bomb->Update();
    gun->Update();
    reload->Update();
    bullet->Update();
    bullet2->Update();
    bullet3->Update();
    bullet4->Update();
    bullet5->Update();
    gauge->Update();
    gaugefront->Update();
    gaugeback->Update();
    stop->Update();
    option->Update();
    continueUI->Update();
    retry->Update();

	Actor::Update();
}

void MainUI::Render()
{
    //UI
    booster->Render();
    bomb->Render();
    reload->Render();
    gun->Render();
    bullet->Render();
    bullet2->Render();
    bullet3->Render();
    bullet4->Render();
    bullet5->Render();
    gaugeback->Render();
    gauge->Render();
    gaugefront->Render();
    stop->Render();
    option->Render();
    continueUI->Render();
    retry->Render();
    open->Render();
    botton->Render();

}


