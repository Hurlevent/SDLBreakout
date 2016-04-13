#include "GameObject.h"

GameObject::GameObject(string name, Point pos)
{
	SetName(name);
	SetPos(pos);
}

void GameObject::SetName(string name)
{
	_name = name;
}

string GameObject::GetName()
{
	return _name;
}

void GameObject::SetPos(Point newPos)
{

}