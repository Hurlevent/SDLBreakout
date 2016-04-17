//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <SDL.h>

#include "Point.h"
#include "Color.h"
#include "Window.hpp"
#include "InputManager.h"
#include "IRenderable.hpp"


using std::string;

class GameObject : public Breakout::IRenderable
{
public:
	GameObject();
	GameObject(string name, Point pos, Point size, SDL_Color color, int textureID);
	virtual ~GameObject()override;

	void SetObjectInfo(string name, Point pos, Point size, SDL_Color color, int textureID);
	void SetName(string name);
	void SetPos(Point newPos);
	void SetSize(Point size);
	void SetColor(SDL_Color color);
	void SetTextureID(int textureID);

	string GetName();

protected:
	string m_name;
	Point m_pos;
	Point m_size;
	SDL_Color m_color;
	int m_texture_id;
};

#endif // !GAMEOBJECT_H


