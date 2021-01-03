#ifndef _CRESOURCE_H_
#define _CRESOURCE_H_
#pragma once
// -----------
//#include "Collision.h"
#include <SDL.h>
#include <vector>
#include <string>
#include "Globals.h"

class CResource
{
public:
	CResource(const std::string& aName, SDL_Rect aRect, const std::string& aPath);
	~CResource();

	void Init();
	void CleanUp();

public:
	//Animations??
	std::string mName;
	std::string mPath;
	SDL_Rect mRect;
	std::vector<SDL_Rect> mBlitRects;
	SDL_Texture* mpTexture;
};

#endif