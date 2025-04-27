#include "LeeGameObject.h"

lee::GameObject::GameObject() : mx{ 0 }, my{ 0 }
{
}

lee::GameObject::~GameObject()
{
}

void lee::GameObject::setPosition(float x, float y)
{
	mx = x;
	my = y;
}

float lee::GameObject::GetPositionX()
{
	return mx;
}

float lee::GameObject::GetPositionY()
{
	return my;
}
