#include <stdio.h>
#include <iostream>
#include "App.h"
#include "Globals.h"

using namespace std;

#define M_EXIT_SUCCESS 1
#define M_EXIT_FAILURE 0

enum class MainState {
	CREATE_STATE,
	START_STATE,
	UPDATE_STATE,
	CLEAN_UP_STATE,
	EXIT_STATE,
};

App* app = nullptr;

int WinMain(int argc, char ** argv)
{
	int ret = M_EXIT_FAILURE;

	MainState state = MainState::CREATE_STATE;

	while (state != MainState::EXIT_STATE)
	{
		switch (state)
		{

		case MainState::CREATE_STATE:
			// ( ---------- World Creation -------------)
			app = new App();
			state = MainState::START_STATE;

			break;

		case MainState::START_STATE:
			// ( --------- World Starts -------------- )
			if (app->Start() == false)
			{
				state = MainState::EXIT_STATE;
			}
			else
			{
				state = MainState::UPDATE_STATE;
			}
			break;
		case MainState::UPDATE_STATE:
		{
			// ( --------- World Updates -------------- )
			int update_return = app->Update();

			if (update_return == UPDATE_ERROR)
			{
				LOG("Application update exits with error.\n");
				state = MainState::EXIT_STATE;
			}
			else if (update_return == UPDATE_STOP)
			{
				state = MainState::CLEAN_UP_STATE;
			}

			break;
		}
		case MainState::CLEAN_UP_STATE:
			// ( --------- World Finishes -------------- )
			if (app->CleanUp() == false)
			{
				state = MainState::EXIT_STATE;
			}
			else
			{
				state = MainState::UPDATE_STATE;
			}
			state = MainState::EXIT_STATE;
			ret = M_EXIT_SUCCESS;
			break;
		}
	}

	delete app;
	return ret;
}