#pragma once

#include "SDLGameObject.hpp"
#include "InputHandler.hpp"
#include "GameObjectFactory.hpp"

class Player : public SDLGameObject 
{
public:
	Player();
	~Player();

public: 
	/*void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();*/

	virtual void draw();
	virtual void update();
	virtual void clean();

	virtual void load(const LoadParams* pParams) override;

private:
	void handleInput();
};

class PlayerCreator : public BaseCreator
{
	virtual GameObject* createGameObject() const override {
		return new Player();
	}
};