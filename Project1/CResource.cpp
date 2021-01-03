#include "CResource.h"
#include "App.h"
#include "CModuleRender.h"

CResource::CResource(const std::string& aName, SDL_Rect aRect, const std::string& aPath) :
	mName(aName),
	mRect(aRect),
	mPath(aPath)
{
}

CResource::~CResource()
{
}

void CResource::Init()
{
	mpTexture = app->mpModuleRender->LoadTexture(mPath);
}

void CResource::CleanUp()
{
	SDL_DestroyTexture(mpTexture);
}
