#ifndef IMenu_h
#define IMenu_h

#include "Window.hpp"
#include "InputManager.h"

namespace Breakout {
	class IMenu {
	public:
		virtual int GetClick(const Window * win, const InputManager * input = nullptr) = 0;
	};
}

#endif 
