#pragma once
#include <RenderTaskPool/Component.h>
class GUI
{
public:
    static GUI& Get() {
        static GUI ins;
        return ins;
    }
	void Init();

	bool BeforeRender(entt::registry& reg);

	bool AfterRender();

	void Exit();

private:
    void DealCommand(entt::registry& reg);

    void ShowMainMenu();

private:
    MM::EntityEditor<entt::entity> m_editor;
};

