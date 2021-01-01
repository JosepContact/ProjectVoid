#include "App.h"

#include <windows.h>

App::App()
{
	// ----- Create Modules ----

	// ----- Add Modules to List ---

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
	/*for (list<Module*>::iterator it = listmodules.begin(); it != listmodules.end(); ++it) {
		if ((*it) != nullptr && ret == true) {
			ret = (*it)->Start();
		}
	}*/
	return ret;
}

update_status App::Update()
{
	if (mQuit)
	{
		return UPDATE_STOP;
	}
	update_status ret = UPDATE_CONTINUE;

	/*list<Module*>::iterator it = listmodules.begin();

	while (it != listmodules.end() && ret == UPDATE_CONTINUE)
	{
		if ((*it) != nullptr)
		{
			ret = (*it)->Update();
		}
		++it;
	}*/

	return ret;
}

bool App::CleanUp()
{
	bool ret = true;
	/*for (std::list<module*>::iterator it = listmodules.begin(); it != listmodules.end(); ++it) {
		if ((*it) != nullptr && ret == true) {
			ret = (*it)->cleanup();
		}
	}*/
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