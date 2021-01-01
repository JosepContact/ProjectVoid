#ifndef __CMODULEWINDOW_H__
#define __CMODULEWINDOW_H__
#pragma once
//-----
#include "CModule.h"

#include <SDL.h>
//----

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

	SDL_Window* GetWindow() const;
	SDL_Surface* GetScreenSurface() const;

private:
	SDL_Window* mpWindow;				//Pointer to game window.
	SDL_Surface* mpScreenSurface;			//Pointer to screen surface.
};

#endif // __CModuleWindow_H__