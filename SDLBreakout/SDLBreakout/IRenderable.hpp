//
//  IMovable.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

// This is an interface that all game_objects is supposed to inherit from

#ifndef IRenderable_hpp
#define IRenderable_hpp

#include "Renderer.h"
#include "InputManager.h"

namespace Breakout {
    class IRenderable{
    public:
        virtual void render_object(const Renderer * rend, const InputManager * input = nullptr) = 0;
		virtual ~IRenderable(){}
    };
}

#endif /* IMovable_hpp */

