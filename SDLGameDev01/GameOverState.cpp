#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "StateParser.hpp"
#include "MenuButton.hpp"
#include "PlayState.hpp"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain() {
	TheGame::Instance()->getStateMache()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay() {
	TheGame::Instance()->getStateMache()->changeState(new PlayState());
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks) {
	// go trough the game objects
	for (int i = 0; i < m_gameObjects.size(); i++) {
		// if they are of type MenuButton then assign a callback based on the id passed in from the file
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

void GameOverState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

void GameOverState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

bool GameOverState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("test.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);

	std::cout << "entering GameOverState" << std::endl;
	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}

	for (int i = 0; i < m_textureIDList.size(); i++) {
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	TheInputHandler::Instance()->reset();

	return true;
}