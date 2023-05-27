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
    
    objects = ObjectPool::AirplaneCreate();

    for (Airplane* airplane : objects)
        airplane->LoadFile("Airplane.xml");

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
    
    for (Airplane* airplane: objects)
        airplane->RenderHierarchy();

    ImGui::End();
    

    

    Cam->Update();
    grid->Update();

    for (Airplane* airplane : objects)
        airplane->Update();

}

void Scene2::LateUpdate()
{
   
}

void Scene2::Render()
{
    Camera::main->Set();



    grid->Render();
    for (Airplane* airplane : objects)
        airplane->Render();
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