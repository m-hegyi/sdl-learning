#include <iostream>
#include "MenuState.hpp"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter() {
	if (!TheTextureManager::Instance()->load("imgs/button.png", "playbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("imgs/exit.png", "exitbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* button1 = new MenuButton(new LoadParams(100, 100, 200, 70, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoadParams(100, 300, 200, 75, "exitbutton"), s_exitFromMenu);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState" << std::endl;
	return true;
}

bool MenuState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	std::cout << "leaving MenuState" << std::endl;
	return true;
}

void MenuState::s_menuToPlay() {
	TheGame::Instance()->getStateMache()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu() {
	TheGame::Instance()->quit();
}
