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

    mainUI = MainUI::Create();
    mainUI->player = player;
    

    //Cannon 생성
    cannon = Cannon::Create();
    cannon->LoadFile("Cannon1.xml");
    /////////////////////////////////
    mainUI->cannon = cannon;
    player->cannon = cannon;

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
   
    //////////////////////////
    grid->RenderHierarchy();
    Cam->RenderHierarchy();
    player->RenderHierarchy();
    //cannon GUi생성
    cannon->RenderHierarchy();
    mainUI->Hierarchy();
    
    for (Airplane* airplane: airplanes)
        airplane->RenderHierarchy();


    // 플레이어 날리기 실험용 추가본

    // 캐논 게이지 추가
   
    if (mainUI->botton->Find("playbotton")->visible == false && INPUT->KeyPress(VK_SPACE))
    {
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
        cannon->Gauge += (mainUI->gaugefront->Find("GaugeFront")->scale.y * 200.0f) * DELTA;
    }

    // 캐논 발사되는 순간
    if (mainUI->botton->Find("playbotton")->visible == false && INPUT->KeyUp(VK_SPACE))
    {
        mainUI->gaugefront->Find("GaugeFront")->visible = false;
        mainUI->gauge->Find("Gauge")->visible = false;
        mainUI->gaugeback->Find("GaugeBack")->visible = false;
        player->visible = true;
        
        player->scalar  = cannon->Gauge;
        player->SetVelocity();
        player->IsFire = true;
        player->gravity = 10.0f;
        Camera::main = (Camera*)player->Find("BackCam");
    }

    // 캐논 발사 전 위치 및 회전각도 조정
    if (player->IsFire == false)
    {
        player->visible = false;
        player->SetPlayerWorldPos(cannon->Find("cannonJoint")->GetWorldPos());
        player->SetPlayerRotationX(-(cannon->Find("cannonJoint")->rotation.x + (90 * TORADIAN)));      
    }

    // 추후 충돌시 애니메이션 변경용
    if (INPUT->KeyDown('1'))
    {
        player->ChangeAni();
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

}

void Scene2::LateUpdate()
{
    for (Airplane* airplane : airplanes)
    {
        airplane->LateUpdate();
    }
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

    //////////////////
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