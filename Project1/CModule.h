#ifndef __CMODULE_H__
#define __CMODULE_H__
#pragma once
//----------
#include "Globals.h"
// ------------
#include <string>

class CModule
{
public:
	//Constructor.
	CModule(const std::string& aName = "Module", bool aStartEnabled = true);
	
	//Destructor.
	virtual ~CModule();
	
	//Starts module.
	virtual bool Start();
	
	// Cleans up the module.
	virtual bool CleanUp();
	
	// Updates the module.
	virtual update_status Update();
	
	// Gets the module name.
	// @return Module name.
	const std::string GetModuleName() const;

private:
	bool mEnabled;
	std::string mModuleName;
};

#endif //_MODULE_H_#pragma once
