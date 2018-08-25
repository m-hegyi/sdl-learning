#pragma once

#include <iostream>
#include <string>
#include <SDL.h>

#include "TextureManager.hpp"
#include "LoadParams.hpp"

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:
	GameObject(const LoadParams* pParams) {}
	~GameObject() {};
};

