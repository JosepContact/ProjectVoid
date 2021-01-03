#include "App.h"

#include <windows.h>

App::App() : 
	mQuit(false)
{
	// ----- Create Modules ----
	mpModuleFileSystem = new CModuleFileSystem("ModuleFileSystem");
	mpModuleWindow	= new CModuleWindow("ModuleWindow");
	mpModuleRender	= new CModuleRender("ModuleRender");
	mpModuleInput	= new CModuleInput("ModuleInput");
	mpModulePlayer = new CModulePlayer("ModulePlayer");
	mpModuleResources = new CModuleResources("ModuleResources");
	// ----- Add Modules to List ---
	mModuleList.push_back(mpModuleWindow);
	mModuleList.push_back(mpModuleRender);
	mModuleList.push_back(mpModuleInput);
	mModuleList.push_back(mpModulePlayer);
	mModuleList.push_back(mpModuleFileSystem);
	mModuleList.push_back(mpModuleResources);
}


App::~App()
{
	for (std::list<CModule*>::reverse_iterator rit = mModuleList.rbegin(); rit != mModuleList.rend(); ++rit)
	{
		if ((*rit) != nullptr)
			RELEASE(*rit);
	}
	mModuleList.clear();
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
		return update_status::UPDATE_STOP;
	}
	update_status ret = update_status::UPDATE_CONTINUE;

	for (const auto& Module : mModuleList)
	{
		ret = Module->Update();
		if (ret != update_status::UPDATE_CONTINUE)
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