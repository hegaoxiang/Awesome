#pragma once
#include"RenderTaskPool/RenderTaskPool.h"
class Engine
{
public:
    void Init();

    void Run();
    void Exit();
    static RenderTasks* GetRenderTaskPool()
    {
        static RenderTasks pool;
        return &pool;
    }
private:
    
};

