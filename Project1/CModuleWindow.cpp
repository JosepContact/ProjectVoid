#include "CModuleWindow.h"
#include <stdio.h>

//Screen dimension constants
const uint SCREEN_WIDTH = 640;
const uint SCREEN_HEIGHT = 480;

CModuleWindow::CModuleWindow(const std::string& aModuleName, bool aEnabled) :
	mpWindow(nullptr),
	mpScreenSurface(nullptr)
{
}

CModuleWindow::~CModuleWindow()
{
}

bool CModuleWindow::Start()
{
	bool ReturnValue(true);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		mpWindow = SDL_CreateWindow("Pokemon Cocos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (mpWindow == nullptr)
		{
			throw("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			mpScreenSurface = SDL_GetWindowSurface(mpWindow);

			//Fill the surface white
			SDL_FillRect(mpScreenSurface, NULL, SDL_MapRGB(mpScreenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(mpWindow);
		}
	}
	return ReturnValue;
}

bool CModuleWindow::CleanUp()
{
	//Destroy window
	SDL_DestroyWindow(mpWindow);

	//Quit SDL subsystems
	SDL_Quit();

	return true;
}

SDL_Window * CModuleWindow::GetWindow() const
{
	return mpWindow;
}

SDL_Surface * CModuleWindow::GetScreenSurface() const
{
	return mpScreenSurface;
}
