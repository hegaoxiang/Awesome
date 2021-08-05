#pragma once
#include<string>
#include<memory>
#include<vector>
#include <iostream>
#include <ImGui/imgui.h>
class Renderer
{
public:
    virtual ~Renderer() {};
    virtual std::string getName()const = 0;
    virtual void render()const = 0;
};

class RenderTasks
{
    using RendererPtr = std::unique_ptr<Renderer>;
public:
    RenderTasks() {
        std::cout << "RenderTasks construct!"<<std::endl;
    }
    static RenderTasks* Get()
    {
        static RenderTasks ins;
       
        return &ins;
    }
    void addRender(RendererPtr render);

    void render();

    void deleteRender();
private:
    std::vector<RendererPtr> m_data;
};
using RegisterRenderFunc = void(*)(RenderTasks* rt);
using RegisterRenderImGuiFunc = void(*)(RenderTasks* rt, ImGuiContext* imCtx);

#define REGISTER_RENDER(Type) \
extern "C"  __declspec(dllexport) void RegisterRender(RenderTasks* rt){ \
   rt->addRender(std::make_unique<Type>());\
}
#define REGISTER_RENDER_IMGUI(Type) \
extern "C"  __declspec(dllexport) void RegisterRender(RenderTasks* rt,ImGuiContext* imCtx){ \
   ImGui::SetCurrentContext(imCtx);\
   rt->addRender(std::make_unique<Type>());\
}