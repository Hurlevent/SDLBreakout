//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef IRenderable_hpp
#define IRenderable_hpp

#include "Renderer.h"
#include "InputManager.h"
#include "Timer.h"

namespace Breakout {
    class IRenderable{
    public:
        virtual void render_object(const Renderer * rend, const InputManager * input = nullptr, const Timer * timer = nullptr) = 0;
		virtual ~IRenderable(){}
    };
}

#endif /* IMovable_hpp */

