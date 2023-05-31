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

    //Cannon ����
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
   
    //////////////////////////
    grid->RenderHierarchy();
    Cam->RenderHierarchy();
    player->RenderHierarchy();
    //cannon GUi����
    cannon->RenderHierarchy();
    
    for (Airplane* airplane: airplanes)
        airplane->RenderHierarchy();


    // �÷��̾� ������ ����� �߰���

    // ĳ�� ������ �߰�
    if (INPUT->KeyPress(VK_SPACE))
    {
        cannon->Gauge += 100 * DELTA;
    }

    // ĳ�� �߻�Ǵ� ����
    if (INPUT->KeyUp(VK_SPACE))
    {
        player->visible = true;
        player->scalar = cannon->Gauge;
        player->IsFire = true;
        player->gravity = 10.0f;
        Camera::main = (Camera*)player->Find("BackCam");
    }

    // ĳ�� �߻� �� ��ġ �� ȸ������ ����
    if (player->IsFire == false)
    {
        player->visible = false;
        player->SetPlayerWorldPos(cannon->Find("Cannon")->GetWorldPos());
        player->SetPlayerRotationX(cannon->Find("Cannon")->rotation.x + (90 * TORADIAN));
    }

    // �÷��̾� �̵�
    player->MovePlayer(player->scalar, cannon->Direction);

    // �÷��̾� �߻� �� ȸ��
    if (player->IsFire)
    {
        Vector3 velocity
            = (cannon->Direction * player->scalar) - (UP * player->gravity);

        player->Find("HoleBone")->rotation.x = (-atan2f(velocity.y, velocity.z) + (90 * TORADIAN));

        cout << player->Find("HoleBone")->rotation.x << endl;
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
   
}

void Scene2::Render()
{
    Camera::main->Set();

    grid->Render();
    player->Render();
    mainUI->Render();
    
    for (Airplane* airplane : airplanes)
        airplane->Render();
    //Cannon Render
    cannon->Render();

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