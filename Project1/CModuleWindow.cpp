#include "CModuleWindow.h"
#include <stdio.h>

//Screen dimension constants
const uint SCREEN_WIDTH = 1080;
const uint SCREEN_HEIGHT = 720;

CModuleWindow::CModuleWindow(const std::string& aModuleName, bool aEnabled) :
	mpWindow(nullptr),
	mpScreenSurface(nullptr),
	mScreenWidth(SCREEN_WIDTH),
	mScreenHeight(SCREEN_HEIGHT)
{
}

CModuleWindow::~CModuleWindow()
{
	//Quit SDL subsystems
	SDL_Quit();
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
		mpWindow = SDL_CreateWindow("Pokemon Cocos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
		if (mpWindow == nullptr)
		{
			throw("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			mpScreenSurface = SDL_GetWindowSurface(mpWindow);

			//Fill the surface white
			SDL_FillRect(mpScreenSurface, 0, SDL_MapRGB(mpScreenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(mpWindow);
		}
	}
	return ReturnValue;
}

bool CModuleWindow::CleanUp()
{
	//Destroy window surface.
	SDL_FreeSurface(mpScreenSurface);
	//Destroy window
	SDL_DestroyWindow(mpWindow);
	return true;
}

update_status CModuleWindow::Update()
{
	return update_status::UPDATE_CONTINUE;
}

SDL_Window * CModuleWindow::GetWindow() const
{
	return mpWindow;
}

SDL_Surface * CModuleWindow::GetScreenSurface() const
{
	return mpScreenSurface;
}

void CModuleWindow::GetScreenDimensions(uint& width, uint& height) const
{
	width = mScreenWidth;
	height = mScreenHeight;
}
