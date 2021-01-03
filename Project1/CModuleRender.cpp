#include "CModuleRender.h"
#include "CModuleWindow.h"
#include "App.h"
// ------
#include "SDL_image.h"


const std::string IMAGE_PATH = "../data/sprites/froakie.png";

CModuleRender::CModuleRender(const std::string& aModuleName, bool aEnabled) :
	mpTestImage(nullptr),
    mpRenderer(nullptr),
    mpTexture(nullptr)
{
}

CModuleRender::~CModuleRender()
{
}

bool CModuleRender::Start()
{
	bool ret(true);

    mpRenderer = SDL_CreateRenderer(app->mpModuleWindow->GetWindow(), -1, 0);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		LOG("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		ret = false;
	}

	//Load splash image
    mpTestImage = LoadSurface(IMAGE_PATH.c_str());
    //mpTexture = SDL_CreateTextureFromSurface(mpRenderer, mpTestImage);
    SDL_BlitSurface(mpTestImage, NULL, app->mpModuleWindow->GetScreenSurface(), NULL);
	return ret;
}

SDL_Surface* CModuleRender::LoadSurface(std::string path)
{
    //The final optimized image
    SDL_Surface* optimizedSurface = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
    {
        LOG("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, app->mpModuleWindow->GetScreenSurface()->format, 0);
        if (optimizedSurface == NULL)
        {
            LOG("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

bool CModuleRender::CleanUp()
{
	SDL_FreeSurface(mpTestImage);
    IMG_Quit();
	return true;
}

update_status CModuleRender::Update()
{
   // SDL_RenderCopy(mpRenderer, mpTexture, NULL, NULL);
    //SDL_RenderPresent(mpRenderer);

    return update_status::UPDATE_CONTINUE;
}
