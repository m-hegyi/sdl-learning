#pragma once

#include <vector>

#include "MenuState.hpp"

class GameOverState : public MenuState
{
public:
	
	virtual void render();
	virtual void update();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; };

private:
	static void s_gameOverToMain();
	static void s_restartPlay();

	virtual void setCallbacks(const std::vector<Callback>&callbacks) override;

	static const std::string s_gameOverID;
	std::vector<GameObject*> m_gameObjects;
};

