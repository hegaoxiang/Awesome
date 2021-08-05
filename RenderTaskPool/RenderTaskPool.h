#pragma once
#include<string>
#include<memory>
#include<vector>
#include <iostream>
#include <ImGui/imgui.h>
#include <unordered_map>
class Renderer
{
public:
    bool m_use = true;
    virtual ~Renderer() {};
    virtual std::string getName()const = 0;
    bool getStatus()const { return m_use; }
    virtual void render()const = 0;
};

class RenderTasks
{
    using RendererPtr = std::unique_ptr<Renderer>;
public:
    inline const std::unordered_map<std::string, RendererPtr>& getPlugins()const
    {
        return m_data;
    }

    void loadRender(RendererPtr render);

    void render();

    void activeRender(const std::string& name);
    void stopRender(const std::string& name);
    void unloadRender(const std::string& name);
private:
    std::unordered_map<std::string, RendererPtr> m_data;
};
using RegisterRenderImGuiFunc = void(*)(RenderTasks* rt, ImGuiContext* imCtx);


#define REGISTER_RENDER_IMGUI(Type) \
extern "C"  __declspec(dllexport) void RegisterRender(RenderTasks* rt,ImGuiContext* imCtx){ \
   ImGui::SetCurrentContext(imCtx);\
   rt->loadRender(std::make_unique<Type>());\
}