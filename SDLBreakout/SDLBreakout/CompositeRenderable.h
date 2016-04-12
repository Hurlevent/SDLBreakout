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
#include <algorithm>
#include "IRenderable.hpp"
#include "IMenu.h"

namespace Breakout {
    
    // Do you remember the design pattern composite??
    // I think it can be used for updating the positions of our gameObjects
    
    class CompositeRenderable : public IRenderable, public IMenu{
    public:
        CompositeRenderable();
        ~CompositeRenderable();
        
		void add(IRenderable * element) { children.push_back(element); };
		void addMenu(IMenu * element) { startChildren.push_back(element); };
		void addpos(IMenu * element) { posChildren.push_back(element); };

		void SetPosition(const int posx, const int posy) { for (int i = 0; i < posChildren.size(); i++)posChildren[i]->SetPosition(posx,posy); };
		int GetClick(const Window * win, const InputManager * input) { for (int i = 0; i < startChildren.size(); i++)return startChildren[i]-> GetClick(win, input); };
		void render_object(const Window * win, const InputManager * input) { for (int i = 0; i < children.size(); i++)children[i]->render_object(win, input); };

		
    private:
        std::vector<IRenderable *> children;
		std::vector<IMenu *> startChildren;
		std::vector<IMenu *> posChildren;
		
		
	};
    
    CompositeRenderable::CompositeRenderable(){};
    CompositeRenderable::~CompositeRenderable(){};
}


#endif /* CompositeRenderable_h */
