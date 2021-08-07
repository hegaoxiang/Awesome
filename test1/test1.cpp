#include <RenderTaskPool/RenderTaskPool.h>
#include <iostream>
#include <RenderTaskPool/Component.h>

namespace Component
{
	struct Test1
	{
		float t1;
		float t2;
	};
}
namespace MM {
	template <>
	void ComponentEditorWidget<Component::Test1>(entt::registry& reg, entt::registry::entity_type e)
	{
		auto& t = reg.get<Component::Test1>(e);
		ImGui::InputFloat("t1", &t.t1);
		ImGui::InputFloat("t2", &t.t2);
	}
}

REGISTER_COMPONENT(Test1)

class Test1:public System
{
public:
	std::string getName() const override
	{
		return ("test1");
	}


	void onUpdate(entt::registry& reg) const override
	{
		ImGui::Begin(this->getName().data());
		reg.view<Component::TRS>().each([](auto e,Component::TRS& t) {
			ImGui::Text("ID %d TRS %d",entt::to_integral(e),t.x);
			});
		
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
