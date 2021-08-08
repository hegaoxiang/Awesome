#include <iostream>
#include <RenderTaskPool/Component.h>
#include <RenderTaskPool/RenderTaskPool.h>

/*

//////////////////////////////////////////////////////////////////////////
namespace Component
{
	struct ExampleComponent
	{
		float exampleVar;
		...
	};
}

//////////////////////////////////////////////////////////////////////////
namespace MM {
	template <>
	void ComponentEditorWidget<Component::ExampleComponent>(entt::registry& reg, entt::registry::entity_type e)
	{
		auto& t = reg.get<Component::ExampleComponent>(e);
		ImGui::InputFloat("exampleVar", &t.exampleVar);
		...
	}
}
//////////////////////////////////////////////////////////////////////////
REGISTER_COMPONENT(ExampleComponent)
//////////////////////////////////////////////////////////////////////////

*/

/*
//////////////////////////////////////////////////////////////////////////
class ExampleSystem :public System
{
public:
	std::string getName() const override
	{
		return ("ExampleSystem");
	}


	void onUpdate(entt::registry& reg) const override
	{
		ImGui::Begin(this->getName().data());
		reg.view<Component::ExampleSystem>().each([](auto e, Component::ExampleSystem& t) {

			ImGui::Text("ID %d ExampleSystem %d", entt::to_integral(e), t.exampleVar);

			...
			});

		ImGui::End();
	}

};

//////////////////////////////////////////////////////////////////////////
REGISTER_RENDER_IMGUI(DeskTest1)
//////////////////////////////////////////////////////////////////////////
*/
