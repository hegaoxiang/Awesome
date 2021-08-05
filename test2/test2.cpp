#include <RenderTaskPool/RenderTaskPool.h>
#include <ImGui/imgui.h>
#include <iostream>

class Test2:public Renderer
{
public:
	std::string getName() const override
	{
		return ("test2");
	}


	void render() const override
	{
		ImGui::Begin(this->getName().data());
		std::cout << "u are sb\n";
		ImGui::End();
	}

};

REGISTER_RENDER_IMGUI(Test2)
