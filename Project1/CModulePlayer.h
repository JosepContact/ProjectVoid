#ifndef __CMODULEPLAYER_H__
#define __CMODULEPLAYER_H__
#pragma once
//-----
#include "CModule.h"
#include <SDL.h>
//----

class CModulePlayer : public CModule
{
public:

	CModulePlayer(const std::string& aModuleName, bool aEnabled = true);

	// Destructor
	virtual ~CModulePlayer();

	// Starts The Window Module.
	bool Start() override;

	// Called before quitting.
	bool CleanUp() override;

	update_status Update() override;

private:
	float mPlayerPosX, mPlayerPosY;
};

#endif // __CModulePlayer_H__