#include <iostream>
#include "PauseState.hpp"
#include "StateParser.hpp"
#include "MainMenuState.hpp"
#include "MenuButton.hpp"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain() {
	TheGame::Instance()->getStateMache()->changeState(new MainMenuState());
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
	StateParser stateParser;
	stateParser.parseState("test.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
	
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_pauseToMain);
	m_callbacks.push_back(s_resumePlay);

	setCallbacks(m_callbacks);

	std::cout << "entering Pause State" << std::endl;
	return true;
}

bool PauseState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	for (int i = 0; i < m_textureIDList.size(); i++) {
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	TheInputHandler::Instance()->reset();

	std::cout << "exiting Pause State" << std::endl;
	return true;
}

 void PauseState::setCallbacks(const std::vector<Callback>&callbacks) {
	// go trough the game objects
	for (int i = 0; i < m_gameObjects.size(); i++) {
		// if they are of type MenuButton then assign a callback based on the id passed in from the file
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}