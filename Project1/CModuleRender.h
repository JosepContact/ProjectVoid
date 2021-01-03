#ifndef __CMODULERENDER_H__
#define __CMODULERENDER_H__
#pragma once
//-----
#include "CModule.h"

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

	SDL_Surface* LoadSurface(SDL_Surface* apSurface, const std::string& aPath);

	void SetTexPosition(float x, float y);

	void BlitTexture();

private:
	SDL_Renderer*	mpRenderer;
	SDL_Surface*	mpTestImage;
	SDL_Texture*	mpTexture;
	SDL_Rect		mRect;
};

#endif // __CModuleRenderw_H__
#pragma once
