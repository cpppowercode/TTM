#include "stdafx.h"
#include "Scene2.h"

Scene2::Scene2()
{

}

Scene2::~Scene2()
{
 
}

void Scene2::Init()
{

    Cam = Camera::Create();
    Cam->LoadFile("Cam.xml");
    Camera::main = Cam;
    Cam->width = App.GetWidth();
    Cam->height = App.GetHeight();
    Cam->viewport.width = App.GetWidth();
    Cam->viewport.height = App.GetHeight();
    
    player = Player::Create();
    player->LoadFile("Player.xml");
    player->Update();

    ///UI 시작화면
    open = UI::Create();
    open->LoadFile("OpenUI.xml");

    botton = UI::Create();
    botton->LoadFile("OpenBottonUI.xml");

    //ITEM UI
    booster = UI::Create();
    booster->LoadFile("BoosterUI.xml");

    bomb = UI::Create();
    bomb->LoadFile("BombUI.xml");

    reload = UI::Create();
    reload->LoadFile("ReloadUI.xml");

    gun = UI::Create();
    gun->LoadFile("GunUI.xml");

    bullet = UI::Create();
    bullet->LoadFile("BulletUI.xml");

    bullet2 = UI::Create();
    bullet2->LoadFile("BulletUI2.xml");

    bullet3 = UI::Create();
    bullet3->LoadFile("BulletUI3.xml");

    bullet4 = UI::Create();
    bullet4->LoadFile("BulletUI4.xml");

    bullet5 = UI::Create();
    bullet5->LoadFile("BulletUI5.xml");

    //Option UI
    stop = UI::Create();
    stop->LoadFile("StopUI.xml");

    option = UI::Create();
    option->LoadFile("OptionUI.xml");
 
    continueUI = UI::Create();
    continueUI->LoadFile("ContinueUI.xml");

    retry = UI::Create();
    retry->LoadFile("RetryUI.xml");

    //Gauge UI
    gauge = UI::Create();
    gauge->LoadFile("GaugeUI.xml");

    gaugefront = UI::Create();
    gaugefront->LoadFile("GaugeFrontUI.xml");

    gaugeback = UI::Create();
    gaugeback->LoadFile("GaugeBackUI.xml");

    //Cannon 생성
    cannon = Cannon::Create();
    cannon->LoadFile("cannon.xml");
    /////////////////////////////////


    airplanes = ObjectPool::AirplaneCreate();

    for (Airplane* airplane : airplanes)
    {
        //airplane->LoadFile("Airplane.xml");
        airplane->player = player;
    }

    grid =  Grid::Create();

}

void Scene2::Release()
{
    //Cam->SaveFile("Cam.xml");

    Cam->Release();
}


void Scene2::Update()
{
    Camera::main->width = App.GetWidth();
    Camera::main->height = App.GetHeight();
    Camera::main->viewport.width = App.GetWidth();
    Camera::main->viewport.height = App.GetHeight();

    Camera::ControlMainCam();

    //debug
    ImGui::Text("FPS: %d", TIMER->GetFramePerSecond());

    //Hierarchy
    ImGui::Begin("Hierarchy");
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
    //////////////////////////
    grid->RenderHierarchy();
    Cam->RenderHierarchy();
    player->RenderHierarchy();
    //cannon GUi생성
    cannon->RenderHierarchy();
    
    for (Airplane* airplane: airplanes)
        airplane->RenderHierarchy();

    ImGui::End();
    
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

    // 플레이어 날리기 실험용 추가본

    // 캐논 게이지 추가
    if (INPUT->KeyPress(VK_SPACE))
    {
        cannon->Gauge += 100 * DELTA;
    }

    // 캐논 발사되는 순간
    if (INPUT->KeyUp(VK_SPACE))
    {
        player->visible = true;
        player->scalar = cannon->Gauge;
        player->IsFire = true;
        player->gravity = 10.0f;
        Camera::main = (Camera*)player->Find("BackCam");
    }

    // 캐논 발사 전 위치 및 회전각도 조정
    if (player->IsFire == false)
    {
        player->visible = false;
        player->SetPlayerWorldPos(cannon->Find("Cannon")->GetWorldPos());
        player->SetPlayerRotationX(cannon->Find("Cannon")->rotation.x + (90 * TORADIAN));
    }

    // 플레이어 이동
    player->MovePlayer(player->scalar, cannon->Direction);

    // 플레이어 발사 후 회전
    if (player->IsFire)
    {
        Vector3 velocity
            = (cannon->Direction * player->scalar) - (UP * player->gravity);

        player->Find("HoleBone")->rotation.x = (-atan2f(velocity.y, velocity.z) + (90 * TORADIAN));

        cout << player->Find("HoleBone")->rotation.x << endl;
    }



    

    Cam->Update();
    grid->Update();

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

    //cannon Update
    cannon->Update();
    player->Update();
    /////////////////////

    for (Airplane* airplane : airplanes)
        airplane->Update();

}

void Scene2::LateUpdate()
{
   
}

void Scene2::Render()
{
    Camera::main->Set();

    grid->Render();
    player->Render();
    
    for (Airplane* airplane : airplanes)
        airplane->Render();
    //Cannon Render
    cannon->Render();

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
    
    
    //////////////////
}

void Scene2::PreRender()
{
}

void Scene2::ResizeScreen()
{
    Cam->width = App.GetWidth();
    Cam->height = App.GetHeight();
    Cam->viewport.width = App.GetWidth();
    Cam->viewport.height = App.GetHeight();
}