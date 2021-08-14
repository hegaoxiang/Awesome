// Awesome.cpp: 定义应用程序的入口点。
//
#include <YDXRender/DXFramework.h>
#include <RenderTaskPool/RenderTaskPool.h>

#include "GUI.h"
#include "ECManager.h"

class SandBox :public YXX::DXFramework
{
public:

	void Init() override
	{
		RenderTasks::Get();

		GUI::Get().Init();

		ECManager::Get().Init();
	}


	void Update(float dt) override
	{
		GUI::Get().Update();

		RenderTasks::Get().render(ECManager::Get().reg);
	}

	void Quit() override
	{
		
	}

	
protected:
	
};
int main()
{
	SandBox s;
	s.Run();
}
