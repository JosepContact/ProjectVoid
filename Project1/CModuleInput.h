#ifndef __CMODULEINPUT_H__
#define __CMODULEINPUT_H__
#pragma once
//-----------
#include "CModule.h"
#include <SDL.h>

#define NUM_KEYS 352
#define NUM_MOUSE_BUTTONS 5

struct SDL_Rect;

enum Controls
{
	__LAST_CONTROLS
};

enum EventWindow
{
	WE_QUIT = 0,
	WE_HIDE = 1,
	WE_SHOW = 2,
	WE_COUNT
};

enum KeyState
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class CModuleInput : public CModule
{

public:

	CModuleInput(const std::string& aModuleName, bool aEnabled = true);

	// Destructor
	virtual ~CModuleInput();

	// Called before render is available
	//bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start() override;

	update_status Update() override;

	// Called before quitting
	bool CleanUp() override;

	// Gather relevant win events
	bool GetWindowEvent(EventWindow ev);

	// Check key states (includes mouse and joy buttons)
	KeyState GetKey(int id) const
	{
		return mpKeyboard[id];
	}

	KeyState GetMouseButtonDown(int id) const
	{
		return mMouseButtons[id - 1];
	}

	// Check if a certain window event happened
	bool GetWindowEvent(int code);

	// Get mouse / axis position
	void GetMousePosition(int& x, int& y);
	void GetMouseMotion(int& x, int& y);

	void StartInputText(std::string* text, int* cursor);
	void EndInputText();

	/*string	GetText();
	uint	TextSize();*/

	SDL_Scancode SelectedKey(std::string s);
	//int controls[static_cast<int>(__LAST_CONTROLS)];

private:
	bool		mWindowEvents[WE_COUNT];
	KeyState*	mpKeyboard;
	KeyState	mMouseButtons[NUM_MOUSE_BUTTONS];
	int			mMouseMotionX;
	int			mMouseMotionY;
	int			mMousePosX;
	int			mMousePosY;

public:
	//text input management
	/*string* input_text = nullptr;
	int* input_cursor = nullptr;
	string		addtext;*/
};

#endif //CMODULEINPUT