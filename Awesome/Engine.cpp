#include"Engine.h"
#include"GUI.h"
#include"RenderTaskPool/RenderTaskPool.h"
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

        RenderTasks::Get()->render();

        GUI::AfterRender();
    }
}

void Engine::Exit()
{
    GUI::Exit();
}
