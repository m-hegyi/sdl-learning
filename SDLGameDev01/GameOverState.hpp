#pragma once

#include <vector>

#include "GameState.hpp"
#include "GameObject.hpp"
#include "Game.hpp"

class GameOverState : public GameState
{
public:
	

	// Inherited via GameState
	virtual void render();

	virtual void update();

	virtual bool onEnter();

	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; };

private:
	static void s_gameOverToMain();
	static void s_restartPlay();

	static const std::string s_gameOverID;

	std::vector<GameObject*> m_gameObjects;
};

