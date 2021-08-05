#include <RenderTaskPool/RenderTaskPool.h>
#include <iostream>
#include <ImGui/imgui.h>

class Test1:public Renderer
{
public:
	std::string getName() const override
	{
		return ("test1");
	}


	void render() const override
	{
		auto c = RenderTasks::Get();
		std::cout << "test1\n";
	}

};

extern "C"  __declspec(dllexport) void RegisterRender(RenderTasks * rt) {
		std::cout << "construct by dll" << std::endl;
		auto c = RenderTasks::Get();
		rt->addRender(std::make_unique<Test1>());
}
//REGISTER_RENDER(Test1)
