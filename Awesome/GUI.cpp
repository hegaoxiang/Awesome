#include "GUI.h"
#include "RenderTaskPool/RenderTaskPool.h"
#include <iostream>
#include <ImGui/imfilebrowser.h>
#include <d3d11.h>
#include <tchar.h>
#include <chrono>
#include <Shlobj.h>
#include <shellapi.h>
#include "Serialize.h"
#include <fstream>
#include "ECManager.h"
enum class Command
{
	LoadPlugin,
	SaveScene,
	OpenScene
};

Command g_CommandList;
// fileBrowser
ImGui::FileBrowser fileDialog;

char* GetCT()
{
	auto now = std::chrono::system_clock::now();
	//通过不同精度获取相差的毫秒数
	uint64_t dis_millseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count()
		- std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count() * 1000;

	time_t tt = std::chrono::system_clock::to_time_t(now);
	auto time_tm = localtime(&tt);

	static char strTime[25] = { 0 };
	sprintf(strTime, "%d_%02d_%02d_%02d_%02d_%02d_%03d", time_tm->tm_year + 1900,
		time_tm->tm_mon + 1, time_tm->tm_mday, time_tm->tm_hour,
		time_tm->tm_min, time_tm->tm_sec, (int)dis_millseconds);
	return strTime;
}



void GUI::Init()
{
    // (optional) set browser properties
	fileDialog.SetTitle("title");
	//fileDialog.SetTypeFilters({ ".h", ".dll" });
}

void GUI::DealCommand(entt::registry& reg)
{
	
	fileDialog.Display();
	if (fileDialog.HasSelected())
	{
		switch (g_CommandList)
		{
		case Command::LoadPlugin:
			if (HMODULE m = LoadLibrary(fileDialog.GetSelected().string().data()); m)
			{
				if (RegisterRenderImGuiFunc regisFunc = (RegisterRenderImGuiFunc)GetProcAddress(m, "RegisterRender"); regisFunc)
					regisFunc(RenderTasks::Get(), ImGui::GetCurrentContext());
				if (RegisterComponentFunc regisFunc = (RegisterComponentFunc)GetProcAddress(m, "RegisterComponent"); regisFunc)
					regisFunc(ECManager::Get().editor, ImGui::GetCurrentContext());
			}
			break;
		case Command::SaveScene:
		{
			auto s = fileDialog.GetSelected().string().append("\\").append(GetCT()).append(".json");

			auto jsonData = Serialization::Serialize(reg);
			std::fstream fo(s, std::ios::out);
			fo << jsonData;
			fo.close();
		}
			break;
		case Command::OpenScene:// 打开场景文件，加载json数据进内存
		{
			auto s = fileDialog.GetSelected().string();

			
			
			if (std::fstream fi(s, std::ios::in); fi)
			{
				std::ostringstream tmp;
				tmp << fi.rdbuf();
				try
				{
					Serialization::UnSerialize(reg, tmp.str());
				}
				catch (const std::exception& e)
				{
					if (ImGui::Begin("Open Scene Fail"))
					{
						ImGui::Text("can not parse the scene");
						ImGui::End();
					}
				}

				fi.close();
			}
			
		}
		break;
		default:
			throw "error in command";
			break;
		}

		fileDialog.ClearSelected();
	}
}
void  GUI::ShowMainMenu()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("Render Plugin"))
		{
			auto& allPlugins = RenderTasks::Get().getPlugins();

			if (ImGui::MenuItem("New plugin"))
			{
				
				auto ct = GetCT();
				static char cmd[200] = { 0 };
				sprintf(cmd, "mkdir %s", ct);
				system(cmd);

				sprintf(cmd, "copy D:\\repo\\Awesome\\Awesome\\Template\\CMakeLists.txt .\\%s", ct);
				system(cmd);

				sprintf(cmd, "copy D:\\repo\\Awesome\\Awesome\\Template\\example.cpp .\\%s", ct);
				system(cmd);

				sprintf(cmd, "copy D:\\repo\\Awesome\\Awesome\\Template\\template.bat  .\\");
				system(cmd);

				ShellExecute(NULL, "open", "template.bat",PCHAR(ct), NULL, SW_HIDE);
			}
			if (ImGui::MenuItem("Load plugin"))
			{
				g_CommandList = Command::LoadPlugin;
				fileDialog.SetTypeFilters({".dll" });
				fileDialog.Open();
			}
			for (auto& it : allPlugins)
			{
				bool iterInvalid = false;
				
				if (ImGui::BeginMenu(it.second->getName().data()))
				{
					if (it.second->getStatus())
					{
						if (ImGui::MenuItem("stop"))
							RenderTasks::Get().stopRender(it.second->getName());
					}
					else 
					{
						if (ImGui::MenuItem("active"))
							RenderTasks::Get().activeRender(it.second->getName());
					}
					ImGui::EndMenu();
				}
				if (iterInvalid)
				{
					break;
				}
			}
			ImGui::EndMenu();
		}

		
		ImGui::EndMainMenuBar();
	}
}

void GUI::ShowInspector()
{
	auto& reg = ECManager::Get().reg;
	auto& editor = ECManager::Get().editor;
	static entt::entity sE = (entt::entity)-1;;
	
	if (ImGui::Begin("Inspector"))
	{
		editor.renderEditor(reg, sE);
		ImGui::End();
	}
}

void GUI::ShowEntityList()
{
	auto& reg = ECManager::Get().reg;
	auto& editor = ECManager::Get().editor;

	if (ImGui::Begin("EntityList"))
	{
		editor.renderEntityList(reg);
		ImGui::End();
	}
}
//////////////////////////////////////////////////////////////////////////
//  Hierarchy
//////////////////////////////////////////////////////////////////////////
void GUI::ShowHierarchy()
{

}

bool GUI::Update()
{
	auto& reg = ECManager::Get().reg;
	auto& editor = ECManager::Get().editor;

	ShowMainMenu();
	DealCommand(reg);

	ShowInspector();
	ShowEntityList();
	if (ImGui::Begin("scene"))
	{
		if (ImGui::Button("SAVE SCENE"))
		{
			g_CommandList = (Command::SaveScene);
			
			fileDialog.SetFileBrowserFlags(ImGuiFileBrowserFlags_SelectDirectory);
			fileDialog.SetTypeFilters({ "" });
			fileDialog.Open();
			
		}
		if (ImGui::Button("Open SCENE"))
		{
			g_CommandList = Command::OpenScene;

			fileDialog.SetFileBrowserFlags(ImGuiFileBrowserFlags_EnterNewFilename);
			fileDialog.SetTypeFilters({ ".json" });
			fileDialog.Open();

		}
		ImGui::End();
	}

	
	/*
	// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	if (show_demo_window)
		ImGui::ShowDemoWindow(&show_demo_window);

	// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
	{
		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
		ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
		ImGui::Checkbox("Another Window", &show_another_window);

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
		ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}

	// 3. Show another simple window.
	if (show_another_window)
	{
		ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		ImGui::Text("Hello from another window!");
		if (ImGui::Button("Close Me"))
			show_another_window = false;
		ImGui::End();
	}
	*/

    return true;
}


