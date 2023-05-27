#include "stdafx.h"
#include "Airplane.h"
#include "ObjectPool.h"
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
    
    // objects = ObjectPool::AirplaneCreate();

    grid =  Grid::Create();
    



}

void Scene2::Release()
{
    //Cam->SaveFile("Cam.xml");

    Cam->Release();
}


void Scene2::Update()
{
    Camera::ControlMainCam();

    //debug
    ImGui::Text("FPS: %d", TIMER->GetFramePerSecond());

    //Hierarchy
    ImGui::Begin("Hierarchy");
    grid->RenderHierarchy();
    Cam->RenderHierarchy();
    ImGui::End();
    
    

    

    Cam->Update();
    grid->Update();



    /*Cam->GetWorldPos().x;
    Cam->GetWorldPos().z;

    Cam->scale.x;
    Cam->rotation.x;*/


}

void Scene2::LateUpdate()
{
   
}

void Scene2::Render()
{
    Camera::main->Set();



    grid->Render();
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