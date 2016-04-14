//
//  CompositeMovable.h
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef CompositeRenderable_h
#define CompositeRenderable_h

#include <vector>
#include "GameObject.h"

namespace Breakout {
    
    // Do you remember the design pattern composite??
    // I think it can be used for updating the positions of our gameObjects
    
    class CompositeRenderable : public IRenderable{
    public:
        CompositeRenderable(){};
        ~CompositeRenderable(){};
        
		void add(GameObject * element) { children.push_back(element); };
	
		void render_object(const Renderer * rend, const InputManager * input) override { for (int i = 0; i < children.size(); i++)children[i]->render_object(rend, input); };

		
    private:
        std::vector<GameObject *> children;
		
	};
}


#endif /* CompositeRenderable_h */
