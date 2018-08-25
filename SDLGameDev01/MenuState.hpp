#pragma once
#include <vector>

#include "TextureManager.hpp"
#include "Game.hpp"
#include "SDLGameObject.hpp"
#include "GameState.hpp"
#include "MenuButton.hpp"

class MenuState : public GameState
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

	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
};

