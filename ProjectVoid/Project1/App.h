#pragma once

#ifndef __APP_H__
#define __APP_H__

// ----------

#include <list>
#include "Globals.h"

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

private:

	bool mQuit;

public:
	void mylog(const char file[], int line, const char* format, ...);
};

extern App* eApp;

#endif //WORLD_H_#pragma once
