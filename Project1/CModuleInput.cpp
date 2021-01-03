#include "CModuleInput.h"
#include "App.h"
#include "CModuleWindow.h"

#define MAX_KEYS 300

CModuleInput::CModuleInput(const std::string& aModuleName, bool aEnabled) :
	mpKeyboard(nullptr),
	mMouseMotionX(0U),
	mMouseMotionY(0U),
	mMousePosX(0U),
	mMousePosY(0U)
{
	mpKeyboard = new KeyState[NUM_KEYS];
	memset(mpKeyboard, KEY_IDLE, sizeof(KeyState) * NUM_KEYS);
	memset(mMouseButtons, KEY_IDLE, sizeof(KeyState) * NUM_MOUSE_BUTTONS);
}

// Destructor
CModuleInput::~CModuleInput()
{
	delete[] mpKeyboard;
}

// Called before the first frame
bool CModuleInput::Start()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	SDL_StopTextInput();
	return true;
}

// Called each loop iteration
update_status CModuleInput::Update()
{
	static SDL_Event event;

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < NUM_KEYS; ++i)
	{
		if (keys[i])
		{
			if (mpKeyboard[i] == KEY_IDLE)
				mpKeyboard[i] = KEY_DOWN;
			else
				mpKeyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (mpKeyboard[i] == KEY_REPEAT || mpKeyboard[i] == KEY_DOWN)
				mpKeyboard[i] = KEY_UP;
			else
				mpKeyboard[i] = KEY_IDLE;
		}
	}

	for (int i = 0; i < NUM_MOUSE_BUTTONS; ++i)
	{
		if (mMouseButtons[i] == KEY_DOWN)
			mMouseButtons[i] = KEY_REPEAT;
		else {
			if (mMouseButtons[i] == KEY_UP)
				mMouseButtons[i] = KEY_IDLE;
		}

	}

	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		case SDL_QUIT:
		{
			mWindowEvents[WE_QUIT] = true;
			app->QuitApp();
			break;
		}

		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
				//case SDL_WINDOWEVENT_LEAVE:
			case SDL_WINDOWEVENT_HIDDEN:
			case SDL_WINDOWEVENT_MINIMIZED:
			case SDL_WINDOWEVENT_FOCUS_LOST:
				mWindowEvents[WE_HIDE] = true;
				break;

				//case SDL_WINDOWEVENT_ENTER:
			case SDL_WINDOWEVENT_SHOWN:
			case SDL_WINDOWEVENT_FOCUS_GAINED:
			case SDL_WINDOWEVENT_MAXIMIZED:
			case SDL_WINDOWEVENT_RESTORED:
				mWindowEvents[WE_SHOW] = true;
				break;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			mMouseButtons[event.button.button - 1] = KEY_DOWN;
			LOG("Mouse button %d down", event.button.button-1);
			break;

		case SDL_MOUSEBUTTONUP:
			mMouseButtons[event.button.button - 1] = KEY_UP;
			LOG("Mouse button %d up", event.button.button-1);
			break;

		case SDL_MOUSEMOTION: 
		{
			// If we change scale we have to apply that to each:
			mMouseMotionX = event.motion.xrel;
			mMouseMotionY = event.motion.yrel;
			mMousePosX = event.motion.x;
			mMousePosY = event.motion.y;
			break;
		}
							break;

		case SDL_TEXTINPUT:
			break;
			//addtext += event.text.text;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool CModuleInput::CleanUp()
{
	LOG("Quitting SDL event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}

bool CModuleInput::GetWindowEvent(EventWindow ev)
{
	return mWindowEvents[ev];
}

// ---------
bool CModuleInput::GetWindowEvent(int code)
{
	return mWindowEvents[code];
}

void CModuleInput::GetMousePosition(int& x, int& y)
{
	x = mMousePosX;
	y = mMousePosY;
}

void CModuleInput::GetMouseMotion(int& x, int& y)
{
	x = mMouseMotionX;
	y = mMouseMotionY;
}

void CModuleInput::StartInputText(std::string* text, int* cursor)
{
	/*input_text = text;
	input_cursor = cursor;
	SDL_StartTextInput();*/
}

//void CModuleInput::EndInputText()
//{
//	SDL_StopTextInput();
//	input_cursor = nullptr;
//	input_text = nullptr;
//}

//std::string CModuleInput::GetText()
//{
//	std::string ret;
//	ret += addtext.c_str();
//	addtext.clear();
//	return ret;
//}

//uint CModuleInput::TextSize()
//{
//	return addtext.size();
//}

SDL_Scancode CModuleInput::SelectedKey(std::string s)
{
	if (s == "Q" || s == "q") {
		return SDL_SCANCODE_Q;
	}
	else if (s == "W" || s == "w") {
		return SDL_SCANCODE_W;
	}
	else if (s == "E" || s == "e") {
		return SDL_SCANCODE_E;
	}
	else if (s == "R" || s == "r") {
		return SDL_SCANCODE_R;
	}
	else if (s == "T" || s == "t") {
		return SDL_SCANCODE_T;
	}
	else if (s == "Y" || s == "y") {
		return SDL_SCANCODE_Y;
	}
	else if (s == "U" || s == "u") {
		return SDL_SCANCODE_U;
	}
	else if (s == "I" || s == "i") {
		return SDL_SCANCODE_I;
	}
	else if (s == "O" || s == "o") {
		return SDL_SCANCODE_O;
	}
	else if (s == "P" || s == "p") {
		return SDL_SCANCODE_P;
	}
	else if (s == "A" || s == "a") {
		return SDL_SCANCODE_A;
	}
	else if (s == "S" || s == "s") {
		return SDL_SCANCODE_S;
	}
	else if (s == "D" || s == "d") {
		return SDL_SCANCODE_D;
	}
	else if (s == "F" || s == "f") {
		return SDL_SCANCODE_F;
	}
	else if (s == "G" || s == "g") {
		return SDL_SCANCODE_G;
	}
	else if (s == "H" || s == "h") {
		return SDL_SCANCODE_H;
	}
	else if (s == "J" || s == "j") {
		return SDL_SCANCODE_J;
	}
	else if (s == "K" || s == "k") {
		return SDL_SCANCODE_K;
	}
	else if (s == "L" || s == "l") {
		return SDL_SCANCODE_L;
	}
	else if (s == "Z" || s == "z") {
		return SDL_SCANCODE_Z;
	}
	else if (s == "X" || s == "x") {
		return SDL_SCANCODE_X;
	}
	else if (s == "C" || s == "c") {
		return SDL_SCANCODE_C;
	}
	else if (s == "V" || s == "v") {
		return SDL_SCANCODE_V;
	}
	else if (s == "B" || s == "b") {
		return SDL_SCANCODE_B;
	}
	else if (s == "N" || s == "n") {
		return SDL_SCANCODE_N;
	}
	else if (s == "M" || s == "m") {
		return SDL_SCANCODE_M;
	}
	else if (s == "tab" || s == "TAB") {
		return SDL_SCANCODE_TAB;
	}
	else if (s == "UP" || s == "up") {
		return SDL_SCANCODE_UP;
	}
	else if (s == "DOWN" || s == "down") {
		return SDL_SCANCODE_DOWN;
	}
	else if (s == "Right" || s == "RIGHT") {
		return SDL_SCANCODE_RIGHT;
	}
	else if (s == "LEFT" || s == "left") {
		return SDL_SCANCODE_LEFT;
	}
	else if (s == "1") {
		return SDL_SCANCODE_1;
	}
	else if (s == "2") {
		return SDL_SCANCODE_2;
	}
	else if (s == "3") {
		return SDL_SCANCODE_3;
	}
	else if (s == "4") {
		return SDL_SCANCODE_4;
	}
	else if (s == "5") {
		return SDL_SCANCODE_5;
	}
	else if (s == "6") {
		return SDL_SCANCODE_6;
	}
	else if (s == "7") {
		return SDL_SCANCODE_7;
	}
	else if (s == "8") {
		return SDL_SCANCODE_8;
	}
	else if (s == "9") {
		return SDL_SCANCODE_9;
	}
	else if (s == "SPACE" || s == "space") {
		return SDL_SCANCODE_SPACE;
	}
	else if (s == "RSHIFT" || s == "rshift") {
		return SDL_SCANCODE_RSHIFT;
	}
	else if (s == "LSHIFT" || s == "lshift") {
		return SDL_SCANCODE_LSHIFT;
	}
	else if (s == "RCTRL" || s == "rctrl") {
		return SDL_SCANCODE_RCTRL;
	}
	else if (s == "LCTRL" || s == "lctrl") {
		return SDL_SCANCODE_LCTRL;
	}
	else {
		return SDL_SCANCODE_0;
	}
}