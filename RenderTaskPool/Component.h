#include <enoki/array.h>
#include <imgui_entt_entity_editor/imgui_entt_entity_editor.hpp>
using namespace enoki;

namespace Component
{
	struct TRS
	{
		float x;
	};

	struct Mesh
	{

	};

	struct Material
	{

	};
};

using RegisterComponentFunc = void(*)(MM::EntityEditor<entt::entity>&);


#define REGISTER_COMPONENT(Type) \
extern "C"  __declspec(dllexport) void RegisterComponent(MM::EntityEditor<entt::entity>& editor){ \
  editor.registerComponent<Component::Type>(#Type);\
}
