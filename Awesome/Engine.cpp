#include"Engine.h"
#include"GUI.h"

void Engine::Init()
{
    GUI::Init();
}

void Engine::Run()
{
    while (true)
    {
        if (false == GUI::BeforeRender())
            break;

        GetRenderTaskPool()->render();

        GUI::AfterRender();
    }
}

void Engine::Exit()
{
    GUI::Exit();
}
