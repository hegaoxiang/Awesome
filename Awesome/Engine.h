#pragma once
#include"RenderTaskPool/RenderTaskPool.h"
#include <entt/entt.hpp>
class Engine
{
public:
    void Init();

    void Run();
    void Exit();
    inline static RenderTasks* GetRenderTaskPool()
    {
        static RenderTasks pool;
        return &pool;
    }

private:

    entt::registry reg;

};

