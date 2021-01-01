#include "App.h"
#include "CModuleWindow.h"

#include <windows.h>

App::App() : 
	mQuit(false)
{
	// ----- Create Modules ----
	std::shared_ptr<CModuleWindow> ModuleWindow = std::make_shared<CModuleWindow>("ModuleWindow");
	// ----- Add Modules to List ---
	mModuleList.push_back(ModuleWindow);
}


App::~App()
{
	//for (std::list<Module*>::reverse_iterator rit = listmodules.rbegin(); rit != listmodules.rend(); ++rit)
	//{
	//	if ((*rit) != nullptr)
	//		RELEASE(*rit);
	//}

	//listmodules.clear();
}

bool App::Start()
{
	bool ret = true;
	for (const auto& Module : mModuleList)
	{
		ret = Module->Start();
	}
	return ret;
}

update_status App::Update()
{
	if (mQuit)
	{
		return UPDATE_STOP;
	}
	update_status ret = UPDATE_CONTINUE;

	for (const auto& Module : mModuleList)
	{
		ret = Module->Update();
		if (ret != UPDATE_CONTINUE)
		{
			break;
		}
	}

	return ret;
}

bool App::CleanUp()
{
	bool ret = true;
	for (const auto& Module : mModuleList)
	{
		ret = Module->CleanUp();
	}
	return ret;
}


void App::QuitApp()
{
	mQuit = true;
}

void App::mylog(const char file[], int line, const char * format, ...)
{
	static char tmp_string[4096];
	static va_list  ap;

	// Construct the string from variable arguments
	va_start(ap, format);
	vsprintf_s(tmp_string, 4096, format, ap);
	va_end(ap);
	OutputDebugString(tmp_string);
}