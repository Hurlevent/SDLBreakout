//
//  Header.h
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef Header_h
#define Header_h

namespace Breakout {
    class IViewport{
    public:
        virtual void set_viewport(const SDL_Rect * viewport) = 0;
    };
}

#endif /* Header_h */
