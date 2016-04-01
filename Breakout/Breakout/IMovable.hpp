//
//  IMovable.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef IMovable_hpp
#define IMovable_hpp

#include "Window.hpp"
#include "InputManager.h"

namespace Breakout {
    class IMovable{
    public:
        virtual void update_position(const Window * win, const InputManager * input = nullptr) = 0;
    };
}

#endif /* IMovable_hpp */
