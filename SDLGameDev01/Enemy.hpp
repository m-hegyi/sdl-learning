#pragma once

#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"

class Enemy : public SDLGameObject
{
public:
	Enemy();
	~Enemy();
public:
	/*void load(int x, int y, int width, int heigth, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clear();*/

	virtual void draw();
	virtual void update();
	virtual void clear();

	virtual void load(const LoadParams* pParams) override;
};

class EnemyCreator : public BaseCreator
{
	virtual GameObject* createGameObject() const override {
		return new Enemy();
	}
};