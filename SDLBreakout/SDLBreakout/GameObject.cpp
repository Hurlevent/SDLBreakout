#include "GameObject.h"
#include "Color.h"


GameObject::GameObject()
{
	GameObject::SetObjectInfo("", Point(0, 0), Point(0, 0), SDL_Color{ 0,0,0 }, 0);
}

GameObject::GameObject(string name, Point pos, Point size, SDL_Color color, int textureID)
{
	GameObject::SetObjectInfo(name, pos, size, color, textureID);
}

GameObject::~GameObject()
{
}

void GameObject::SetObjectInfo(string name, Point pos, Point size, SDL_Color color, int textureID)
{
	SetName(name);
	SetPos(pos);
	SetSize(size);
	SetColor(color);
	SetTextureID(textureID);
}

void GameObject::SetName(string name)
{
	m_name = name;
}

string GameObject::GetName()
{
	return m_name;
}

void GameObject::SetPos(Point newPos)
{
	m_pos = newPos;
}

void GameObject::SetSize(Point size)
{
	m_size = size;
}

void GameObject::SetColor(SDL_Color color)
{
	m_color = color;
}

void GameObject::SetTextureID(int textureID)
{
	m_texture_id = textureID;
}
