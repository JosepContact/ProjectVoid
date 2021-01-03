#ifndef __CMODULERENDER_H__
#define __CMODULERENDER_H__
#pragma once
//-----
#include "CModule.h"
// -----
#include <vector>
#include <SDL.h>
//----

class CModuleRender : public CModule
{
public:

	CModuleRender(const std::string& aModuleName, bool aEnabled = true);

	// Destructor
	virtual ~CModuleRender();

	// Starts The Window Module.
	bool Start() override;

	// Called before quitting.
	bool CleanUp() override;

	update_status Update() override;

	void SetTexPosition(float x, float y);

	SDL_Texture* LoadTexture(const std::string& aPath);

	std::vector<SDL_Texture*> mRenderTextures;
private:
	SDL_Surface* LoadSurface(const std::string& aPath);

private:
	SDL_Renderer*	mpRenderer;
	SDL_Surface*	mpTestImage;
	SDL_Texture*	mpTexture;
	SDL_Rect		mRect;
};

#endif // __CModuleRenderw_H__
#pragma once
