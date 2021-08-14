#include "ECManager.h"
#include <RenderTaskPool/Component.h>
void ECManager::Init()
{
	editor.registerComponent<Component::TRS>("TRS");
	editor.registerComponent<Component::Mesh>("Mesh");
	editor.registerComponent<Component::Material>("Material");
}
