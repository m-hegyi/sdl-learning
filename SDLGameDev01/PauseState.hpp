#pragma once
#include <vector>

#include "MenuState.hpp"
#include "MainMenuState.hpp"

class MenuState;

class PauseState : public MenuState
{
public:

	virtual void render();
	virtual void update();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_pauseID; }

private:

	static void s_pauseToMain();
	static void s_resumePlay();

	virtual void setCallbacks(const std::vector<Callback>&callbacks);

	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;
};

