#include "GameOverState.hpp"
#include "MainMenuState.hpp"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain() {
	TheGame::Instance()->getStateMache()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay() {
	TheGame::Instance()->getStateMache()->changeState(new PlayState());
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
	if (!TheTextureManager::Instance()->load("imgs/gameover.png", "gameovertext", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("imgs/menu.png", "menubutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("imgs/restart.png", "restartbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}

	//GameObject* gameOverText = new AnimatedGraphic(new LoadParams(200, 100, 200, 100, "gameovertext"), 2);
	//GameObject* button1 = new MenuButton(new LoadParams(200, 200, 200, 80, "menubutton"), s_gameOverToMain);
	//GameObject* button2 = new MenuButton(new LoadParams(200, 300, 200, 80, "restartbutton"), s_restartPlay);

	//m_gameObjects.push_back(gameOverText);
	//m_gameObjects.push_back(button1);
	//m_gameObjects.push_back(button2);

	std::cout << "entering GameOverState" << std::endl;
	return true;
}

bool GameOverState::onExit()
{
	return true;
}