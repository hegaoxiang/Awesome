// Awesome.cpp: 定义应用程序的入口点。
//
#include <YDXRender/DXFramework.h>
#include <RenderTaskPool/RenderTaskPool.h>

#include "GUI.h"
#include "ECManager.h"
#include <Tinygltf/tiny_gltf.h>

static std::string GetFilePathExtension(const std::string& FileName) {
	if (FileName.find_last_of(".") != std::string::npos)
		return FileName.substr(FileName.find_last_of(".") + 1);
	return "";
}
class SandBox :public YXX::DXFramework
{
public:
	tinygltf::Model model;
	tinygltf::TinyGLTF loader;
	std::string err;
	std::string warn;


	void Init() override
	{
		RenderTasks::Get();

		GUI::Get().Init();

		ECManager::Get().Init();

		std::string input_filename = "models//Cube//Cube.gltf";
		std::string ext = GetFilePathExtension(input_filename);

		bool ret = false;
		if (ext.compare("glb") == 0) {
			// assume binary glTF.
			ret =
				loader.LoadBinaryFromFile(&model, &err, &warn, input_filename.c_str());
		}
		else {
			// assume ascii glTF.
			ret = loader.LoadASCIIFromFile(&model, &err, &warn, input_filename.c_str());
		}

		if (!warn.empty()) {
			printf("Warn: %s\n", warn.c_str());
		}

		if (!err.empty()) {
			printf("ERR: %s\n", err.c_str());
		}

	}


	void Update(float dt) override
	{
		GUI::Get().Update();

		RenderTasks::Get().render(ECManager::Get().reg);
		

	}

	void Quit() override
	{
		
	}
protected:
	
};
int main()
{
	SandBox s;
	s.Run();
}
