#pragma once

#ifndef __CMODULEWINDOW_H__
#define __CMODULEWINDOW_H__

//#include "pugixml-1.10\src\pugixml.hpp"
#include "CModule.h"


class CModuleWindow : public CModule
{
public:

	CModuleWindow(const std::string& aModuleName, bool aEnabled = true);

	// Destructor
	virtual ~CModuleWindow();

	// Starts The Window Module.
	bool Start() override;

	// Called before quitting.
	bool CleanUp() override;

};

#endif // __CModuleWindow_H__