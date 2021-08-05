#include <RenderTaskPool/RenderTaskPool.h>
#include <iostream>

class Test1:public Renderer
{
public:
	std::string getName() const override
	{
		return ("test1");
	}


	void render() const override
	{
		ImGui::Begin(this->getName().data());
		ImGui::Text("awesome");
		ImGui::End();
	}

};

//extern "C"  __declspec(dllexport) void RegisterRender(RenderTasks * rt) {
//		std::cout << "construct by dll" << std::endl;
//		auto c = RenderTasks::Get();
//		rt->addRender(std::make_unique<Test1>());
//}
REGISTER_RENDER_IMGUI(Test1)
//REGISTER_RENDER(Test1)
