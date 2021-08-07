#include"Engine.h"
#include"GUI.h"

void Engine::Init()
{
    GUI::Get().Init();

	entt::entity e;

	for (size_t i = 0; i < 3; i++) {
		e = reg.create();
	}
}

void Engine::Run()
{
    while (true)
    {
        if (false == GUI::Get().BeforeRender(reg))
            break;

        GetRenderTaskPool()->render(reg);

        GUI::Get().AfterRender();
    }
}

void Engine::Exit()
{
    GUI::Get().Exit();
}
