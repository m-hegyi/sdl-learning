#include "PauseState.hpp"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain() {
	TheGame::Instance()->getStateMache()->changeState(new MenuState());
}

void PauseState::s_resumePlay() {
	TheGame::Instance()->getStateMache()->popState();
}

void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PauseState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter() {
	if (!TheTextureManager::Instance()->load("imgs/resume.png", "resumebutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("imgs/menu.png", "menubutton", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* button1 = new MenuButton(new LoadParams(100, 100, 200, 75, "menubutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoadParams(100, 300, 200, 75, "resumebutton"), s_resumePlay);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering Pause State" << std::endl;
	return true;
}

bool PauseState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");

	TheInputHandler::Instance()->reset();

	std::cout << "exiting Pause State" << std::endl;
	return true;
}