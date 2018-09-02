#pragma once

#include <iostream>
#include <string>
#include <SDL.h>

#include "LoadParams.hpp"

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	// new load function
	virtual void load(const LoadParams* pParams) = 0;

protected:
	GameObject() {}
	~GameObject() {};
};

