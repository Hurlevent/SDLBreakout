//
//  CompositeMovable.h
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef CompositeMovable_h
#define CompositeMovable_h

#include <vector>
#include <algorithm>
#include "IMovable.hpp"

namespace Breakout {
    
    // Do you remember the design pattern composite??
    // I think it can be used for updating the positions of our gameObjects
    
    class CompositeMovable : public IMovable{
    public:
        CompositeMovable();
        ~CompositeMovable();
        void add(IMovable * element){ childMovables.push_back(element);};
        void update_position(const Window * win){for(int i = 0; i < childMovables.size(); i++)childMovables[i]->update_position(win);}
    private:
        std::vector<IMovable *> childMovables;
    };
    
    CompositeMovable::CompositeMovable(){};
    CompositeMovable::~CompositeMovable(){};
}


#endif /* CompositeMovable_h */
