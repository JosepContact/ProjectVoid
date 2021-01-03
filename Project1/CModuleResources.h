#ifndef __CMODULERESOURCES_H__
#define __CMODULERESOURCES_H__
#pragma once
//-----
#include "CModule.h"
#include "CResource.h"
//----
#include <SDL.h>
#include <list>

class CModuleResources : public CModule
{
public:

	CModuleResources(const std::string& aModuleName, bool aEnabled = true);

	// Destructor
	virtual ~CModuleResources();

	// Starts The Window Module.
	bool Start() override;

	// Called before quitting.
	bool CleanUp() override;

	update_status Update() override;

private:
	std::list<CResource*> mpResourcesList;
};

#endif // __CModuleWindow_H__