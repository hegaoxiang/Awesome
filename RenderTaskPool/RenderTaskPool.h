#pragma once
#include<string>
#include<memory>
#include<vector>
#include <iostream>
#include <ImGui/imgui.h>
#include <unordered_map>
#include <entt/entt.hpp>
class System
{
public:
    bool m_use = true;
    virtual ~System() {};
    virtual std::string getName()const = 0;
    bool getStatus()const { return m_use; }
    virtual void onUpdate(entt::registry& reg)const = 0;
};

class RenderTasks
{
    using RendererPtr = std::unique_ptr<System>;
public:
	inline static RenderTasks& Get()
	{
		static RenderTasks pool;
		return pool;
	}
    inline const std::unordered_map<std::string, RendererPtr>& getPlugins()const
    {
        return m_data;
    }

    void loadRender(RendererPtr render);

    void render(entt::registry& reg);

    void activeRender(const std::string& name);
    void stopRender(const std::string& name);
private:
    std::unordered_map<std::string, RendererPtr> m_data;
};
using RegisterRenderImGuiFunc = void(*)(RenderTasks& rt, ImGuiContext* imCtx);


#define REGISTER_RENDER_IMGUI(Type) \
extern "C"  __declspec(dllexport) void RegisterRender(RenderTasks& rt,ImGuiContext* imCtx){ \
   ImGui::SetCurrentContext(imCtx);\
   rt.loadRender(std::make_unique<Type>());\
}