#include "ECManager.h"
#include <RenderTaskPool/Component.h>

namespace MM {
	template <>
	void ComponentEditorWidget<Component::TRS>(entt::registry& reg, entt::registry::entity_type e)
	{
		auto& t = reg.get<Component::TRS>(e);
		//ImGui::
	}

	template <>
	void ComponentEditorWidget<Component::Mesh>(entt::registry& reg, entt::registry::entity_type e)
	{
		auto& t = reg.get<Component::Mesh>(e);
	}

	template <>
	void ComponentEditorWidget<Component::Material>(entt::registry& reg, entt::registry::entity_type e)
	{
		auto& t = reg.get<Component::Material>(e);
		ImGui::InputFloat3("albedo", t.albedo.data());
		ImGui::DragFloat("roughness", &t.roughness, 0.1f, 0, 1);
	}
}

void ECManager::Init()
{
	editor.registerComponent<Component::TRS>("TRS");
	editor.registerComponent<Component::Mesh>("Mesh");
	editor.registerComponent<Component::Material>("Material");
}
