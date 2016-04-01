//
//  IMovable.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef IRenderable_hpp
#define IRenderable_hpp

#include "Window.hpp"
#include "InputManager.h"

namespace Breakout {
    class IRenderable{
    public:
        virtual void render_object(const Window * win, const InputManager * input = nullptr) = 0;
    };
}

#endif /* IMovable_hpp */
