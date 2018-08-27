#pragma once
#include <vector>

#include "PauseState.hpp"
#include "MenuState.hpp"
#include "MenuButton.hpp"


class MainMenuState : public MenuState
{
public:

	virtual void render();
	virtual void update();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:
	// call back function for menu items
	static void s_menuToPlay();
	static void s_exitFromMenu();

	virtual void setCallbacks(const std::vector<Callback>&callbacks);

	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
};

