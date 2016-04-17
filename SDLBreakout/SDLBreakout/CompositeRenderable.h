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
#include "Menu.h"

namespace Breakout {
    
    // Do you remember the design pattern composite??
    // I think it can be used for updating the positions of our gameObjects
    class CompositeRenderable{
    public:
		CompositeRenderable(int window_width, int window_height, int number_of_buttons, int button_width = 100, int button_height = 20) : menu(window_width, window_height, number_of_buttons, button_width, button_height) {};
        ~CompositeRenderable(){};
        
		void add(GameObject * element) { children.push_back(element); };
	
		void ChangeView(int view) { if (view == 0)  function = &CompositeRenderable::UpdateMenu; else function = &CompositeRenderable::UpdateGame; };

		void Update(const Renderer * rend, const InputManager * input, const Timer * timer) { (this->*function)(rend, input, timer); };
		void UpdateGame(const Renderer * rend, const InputManager * input, const Timer * timer) { for (int i = 0; i < children.size(); i++)children[i]->render_object(rend, input, timer); };
		void UpdateMenu(const Renderer * rend, const InputManager * input, const Timer * timer) { menu.render_object(rend, input, timer); };
		
		Menu menu;
    private:
        std::vector<GameObject *> children;
		
		void(CompositeRenderable::*function)(const Renderer * rend, const InputManager * input, const Timer * timer);
	};
}


#endif /* CompositeRenderable_h */
