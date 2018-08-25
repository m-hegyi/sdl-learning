#include <iostream>
#include "PlayState.hpp"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMache()->pushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	//if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1]))) {
		//TheGame::Instance()->getStateMache()->pushState(new GameOverState());
	//}
	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1]))) {
		std::cout << "wat" << std::endl;
		TheGame::Instance()->getStateMache()->pushState(new GameOverState());
	}
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("imgs/helicopter.png", "helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("imgs/helicopter2.png", "helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* player = new Player(new LoadParams(500, 100, 115, 65, "helicopter"));
	GameObject* enemy = new Enemy(new LoadParams(100, 100, 115, 65, "helicopter2"));

	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);

	std::cout << "Entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");

	std::cout << "Leaving PlayState" << std::endl;
	return true;
}

bool PlayState::checkCollision(SDLGameObject * p1, SDLGameObject * p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA	= p1->getPosition().getX();
	rightA	= p1->getPosition().getX() + p1->getWidth();
	topA	= p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB	= p2->getPosition().getX();
	rightB	= p2->getPosition().getX() + p2->getWidth();
	topB	= p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (leftA >= rightB) { return false; }
	if (rightA <= leftB) { return false; }

	return true;
}
