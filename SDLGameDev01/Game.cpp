#include "Game.hpp"
#include <iostream>
#include "MainMenuState.hpp"
#include "MenuButton.hpp"
#include "PlayState.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "AnimatedGraphic.hpp"

Game::Game()
{
}


Game::~Game()
{
}

Game* Game::s_pInstance = NULL;

void Game::render() {
	SDL_RenderClear(m_pRenderer); // Clear the screen

	//TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer, SDL_FLIP_NONE);
	//TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	// loop trough our objects and draw them
	//for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		//m_gameObjects[i]->draw();
	//}

	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer); // Draw the screen
}

void Game::update() {
	m_pGameStateMachine->update();
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::clean() {
	std::cout << "cleaning game" << std::endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
	TheInputHandler::Instance()->clean();
}

bool Game::init(const char* title, int xpos, int ypos, int width, int heigth, bool fullscreen) {
	// Initialize sdl
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		// error
		std::cout << "SDL init failed!" << std::endl;
		return false;
	}
	else {
		std::cout << "SDL initialize success" << std::endl;

		int flags = 0;

		if (fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, heigth, flags);
		if (m_pWindow == NULL) {
			// error
			std::cout << "Window init is failed" << std::endl;
			return false;
		}
		else {
			// init renderer
			std::cout << "Window is initialized" << std::endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer == NULL) {
				// error
				std::cout << "Renderer init is failed" << std::endl;
				return false;
			}
			else {
				std::cout << "Renderer is initialized" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
			}
		}

		TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
		TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
		TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
		TheGameObjectFactory::Instance()->registerType("AnimetidGraphic", new AnimatedGraphicCreator());

		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(new MainMenuState());

		// init bmp
		TextureManager::Instance()->load("imgs/cat.png", "animate", m_pRenderer);
		TheInputHandler::Instance()->initializeJoysticks();
		
	}

	std::cout << "Init success!" << std::endl;
	m_bRunning = true;
	return true;
}

void Game::quit() {
	m_bRunning = false;
}