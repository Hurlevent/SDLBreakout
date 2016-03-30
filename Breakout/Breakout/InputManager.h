#ifndef INPUTMANAGER
#define INPUTMANAGER

#include <SDL.h>

class InputManager
{
public:
	InputManager();
	~InputManager();
	void HandleInputEvents();
	void ClearFlags();
	bool GetFlagUp() const;
	bool GetFlagDown() const;
	bool GetFlagLeft() const;
	bool GetFlagRight() const;
	bool GetFlagSpace() const;
	bool GetFlagEscape() const;
	bool GetFlagQuit() const;
private:
	bool up;
	bool down;
	bool left;
	bool right;
	bool space;
	bool escape;
	bool quit;
	SDL_Event evntHandler;
};

#endif