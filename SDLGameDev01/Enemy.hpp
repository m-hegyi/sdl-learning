#pragma once

#include "SDLGameObject.hpp"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoadParams* pParams);
	~Enemy();
public:
	/*void load(int x, int y, int width, int heigth, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clear();*/

	virtual void draw();
	virtual void update();
	virtual void clear();
};

