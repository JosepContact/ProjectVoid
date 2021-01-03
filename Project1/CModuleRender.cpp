#include "CModuleRender.h"
#include "CModuleWindow.h"
#include "App.h"
// ------
#include "SDL_image.h"


const std::string IMAGE_PATH = "../data/sprites/froakie.png";

CModuleRender::CModuleRender(const std::string& aModuleName, bool aEnabled) :
	mpTestImage(nullptr),
    mpRenderer(nullptr),
    mpTexture(nullptr),
    mRect({0,0,0,0})
{
}

CModuleRender::~CModuleRender()
{
    IMG_Quit();
}

bool CModuleRender::Start()
{
	bool ret(true);

    //Creates Renderer
    mpRenderer = SDL_CreateRenderer(app->mpModuleWindow->GetWindow(), -1, SDL_RENDERER_ACCELERATED);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		LOG("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		ret = false;
	}

	//Load splash image
    mpTestImage = LoadSurface(mpTestImage, IMAGE_PATH);
    mpTexture = SDL_CreateTextureFromSurface(mpRenderer, mpTestImage);
    mRect.w = 600;
    mRect.h = 600;
	return ret;
}

SDL_Surface* CModuleRender::LoadSurface(SDL_Surface* apSurface, const std::string& aPath)
{
    //Load image at specified path
    apSurface = IMG_Load(aPath.c_str());

    SDL_Surface* optimizedSurface = nullptr;

    if (apSurface == nullptr)
    {
        LOG("Unable to load image %s! SDL_image Error: %s\n", aPath.c_str(), IMG_GetError());
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(apSurface, app->mpModuleWindow->GetScreenSurface()->format, 0);
        if (optimizedSurface == NULL)
        {
            LOG("Unable to optimize image %s! SDL Error: %s\n", aPath.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(apSurface);
    }

    return optimizedSurface;
}

void CModuleRender::SetTexPosition(float x, float y)
{
    mRect.x = x;
    mRect.y = y;
}

bool CModuleRender::CleanUp()
{
	SDL_FreeSurface(mpTestImage);
    SDL_DestroyTexture(mpTexture);
    SDL_DestroyRenderer(mpRenderer);
	return true;
}

update_status CModuleRender::Update()
{
    //Clear screen
    SDL_RenderClear(mpRenderer);

    //Set the render draw
    SDL_SetRenderDrawColor(mpRenderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_TRANSPARENT);

    //Render texture to screen
    SDL_RenderCopy(mpRenderer, mpTexture, NULL, &mRect);

    //Update screen
    SDL_RenderPresent(mpRenderer);

    return update_status::UPDATE_CONTINUE;
}
