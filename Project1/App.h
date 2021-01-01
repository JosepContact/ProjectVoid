#pragma once

#ifndef __APP_H__
#define __APP_H__

// ----------
//#include "CModuleRenderer.h"
#include "CModuleWindow.h"

// ---------
#include <list>
#include <memory>
// ---------

#define LOG(format, ...) app->mylog(__FILE__, __LINE__, format, __VA_ARGS__);

// ---------

class App
{
public:
	App();
	virtual ~App();

	bool Start();
	update_status Update();
	bool CleanUp();

	void QuitApp();

	CModuleWindow* mpModuleWindow;
	//CModuleRenderer* mpModuleRenderer;
private:
	std::list<CModule*> mModuleList;			// List containing every app module.
	bool mQuit;									// If true app closes.

public:
	void mylog(const char file[], int line, const char* format, ...);
};

extern App* eApp;

#endif //APP_H
