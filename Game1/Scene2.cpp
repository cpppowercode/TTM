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

    mainUI = MainUI::Create();
    mainUI->player = player;
    mainUI->cannon = cannon;
    
    cannon = Cannon::Create();
    cannon->player = player;
    cannon->mainUI = mainUI;

    airplanes = ObjectPool::AirplaneCreate();
    malphites = ObjectPool::MalphiteCreate();

    for (Airplane* airplane : airplanes)
        airplane->player = player;

    for (Malphite* malphite : malphites)
        malphite->player = player;

    
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
   
    //////////////////////////
    grid->RenderHierarchy();
    Cam->RenderHierarchy();
    player->RenderHierarchy();
    cannon->RenderHierarchy();
    mainUI->Hierarchy();
    
    for (Airplane* airplane: airplanes)
        airplane->RenderHierarchy();
    for (Malphite* malphite : malphites)
        malphite->RenderHierarchy();

    // 플레이어 날리기 실험용 추가본

    // 캐논 게이지 추가
    if (mainUI->botton->Find("playbotton")->visible == false && INPUT->KeyPress(VK_SPACE))
    {
<<<<<<< Updated upstream
        cannon->cannonCharge();
=======
        mainUI->gaugefront->Find("GaugeFront")->scale.y = Util::Saturate(mainUI->gaugefront->Find("GaugeFront")->scale.y, 0.0f, 0.77f);
        if (mainUI->gaugefront->Find("GaugeFront")->scale.y == 0.77f)
        {
            mainUI->gaugefront->Find("GaugeFront")->scale.y = 0.0f;
        }
        else if (mainUI->gaugefront->Find("GaugeFront")->scale.y < 0.4f)
        {
            mainUI->gaugefront->Find("GaugeFront")->scale.y += 0.5f * DELTA;
        }
        else if (mainUI->gaugefront->Find("GaugeFront")->scale.y > 0.4f)
        {
            mainUI->gaugefront->Find("GaugeFront")->scale.y += 3.0f * DELTA;
        }
        else if (mainUI->gaugefront->Find("GaugeFront")->scale.y > 0.68f)
        {
            mainUI->gaugefront->Find("GaugeFront")->scale.y += 7.0f * DELTA;
        }
        cannon->Gauge += (mainUI->gaugefront->Find("GaugeFront")->scale.y * 300.0f) * DELTA;
>>>>>>> Stashed changes
    }

    // 캐논 발사되는 순간
    if (mainUI->botton->Find("playbotton")->visible == false && INPUT->KeyUp(VK_SPACE))
    {
        cannon->cannonShot();
    }

    // 캐논 발사 전 위치 및 회전각도 조정
    if (player->IsFire == false)
    {
        cannon->dissipation();
    }

    ImGui::End();
   
    Cam->Update();
    grid->Update();
    mainUI->Update();
    //cannon Update
    cannon->Update();
    player->Update();
    /////////////////////

    for (Airplane* airplane : airplanes)
        airplane->Update();
    for (Malphite* malphite : malphites)
        malphite->Update();
}

void Scene2::LateUpdate()
{
    mainUI->LateUpdate();

    for (Airplane* airplane : airplanes)
        airplane->LateUpdate();
    for (Malphite* malphite : malphites)
        malphite->LateUpdate();
}

void Scene2::Render()
{
    Camera::main->Set();

    grid->Render();
    player->Render();
    
    for (Airplane* airplane : airplanes)
        airplane->Render();
    for (Malphite* malphite : malphites)
        malphite->Render();

    cannon->Render();
    mainUI->Render();
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