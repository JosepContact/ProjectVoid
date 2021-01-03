#include "App.h"
#include "CModulePlayer.h"
#include "CModuleInput.h"

CModulePlayer::CModulePlayer(const std::string& aModuleName, bool aEnabled) :
	mPlayerPosX(0U),
	mPlayerPosY(0U)
{
}

CModulePlayer::~CModulePlayer()
{
}

bool CModulePlayer::Start()
{
	return true;
}

bool CModulePlayer::CleanUp()
{
	return true;
}

update_status CModulePlayer::Update()
{
	if (app->mpModuleInput->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		mPlayerPosY -= 0.1;
	}
	else if (app->mpModuleInput->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		mPlayerPosY += 0.1;
	}
	else if (app->mpModuleInput->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		mPlayerPosX -= 0.1;
	}
	else if (app->mpModuleInput->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		mPlayerPosX += 0.1;
	}

	app->mpModuleRender->SetTexPosition(mPlayerPosX, mPlayerPosY);

	return update_status::UPDATE_CONTINUE;
}
