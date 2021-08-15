#pragma once
#include <enoki/array.h>
#include <imgui_entt_entity_editor/imgui_entt_entity_editor.hpp>
#include <nlohmann/json.hpp>

namespace Component
{
	struct Parent
	{
		entt::entity parent;
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Parent, parent)
	};
	struct Children
	{
		std::set<entt::entity> children;
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Children, children)
	};

	struct TRS
	{
		float x;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(TRS, x)
	};

	struct Mesh
	{
		std::string path;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Mesh, path)
	};

	struct Material
	{
		Float3 albedo;
		float roughness;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Material, albedo, roughness)
	};
};

using RegisterComponentFunc = void(*)(MM::EntityEditor<entt::entity>&, ImGuiContext* imCtx);


#define REGISTER_COMPONENT(Type) \
extern "C"  __declspec(dllexport) void RegisterComponent(MM::EntityEditor<entt::entity>& editor, ImGuiContext* imCtx){ \
  ImGui::SetCurrentContext(imCtx);\
  editor.registerComponent<Component::Type>(#Type);\
}
