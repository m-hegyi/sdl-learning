#pragma once

#include "SDLGameObject.hpp"

class Player : public SDLGameObject 
{
public:
	Player(const LoadParams* pParams);
	~Player();

public: 
	/*void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();*/

	virtual void draw();
	virtual void update();
	virtual void clean();
};

