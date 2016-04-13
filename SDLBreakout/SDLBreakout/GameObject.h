//GameObject.h
#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "Point.h"
#include "Color.h"

using std::string;

class GameObject
{
public:
	GameObject(string name, Point pos);

	void SetName(string name);
	void SetPos(Point newPos);

	string GetName();

private:
	string _name;
	Point _pos;
	Color color;
	int texture_id;
};

#endif // !GAMEOBJECT_H


