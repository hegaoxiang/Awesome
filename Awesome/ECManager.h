#pragma once
#include <entt/entt.hpp>
#include <imgui_entt_entity_editor/imgui_entt_entity_editor.hpp>

class ECManager
{
public:
	entt::registry reg;
	MM::EntityEditor<entt::entity> editor;

public:
	inline static ECManager& Get()
	{
		static ECManager ins;
		return ins;
	}

	void Init();
};
