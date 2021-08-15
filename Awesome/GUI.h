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

	bool Update();


private:
    void DealCommand(entt::registry& reg);

    void ShowMainMenu();

    void ShowInspector();

    void ShowEntityList();

protected:
    void ShowHierarchy();
private:
  
};

