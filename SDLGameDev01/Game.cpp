#include "Game.hpp"
#include <iostream>


Game::Game()
{
}


Game::~Game()
{
}

void Game::render() {
	SDL_RenderClear(m_pRenderer); // Clear the screen

	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer, SDL_FLIP_NONE);
	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer); // Draw the screen
}

void Game::update() {
	m_currentFrame = int((SDL_GetTicks() / 100)) % 6;
	/*int counter = int(SDL_GetTicks() / 100) % 6;
	if (counter < 4) {
		m_sourceRectangle.x = 128 * counter;
		m_sourceRectangle.y = 54;
	}
	else {
		m_sourceRectangle.x = 128 * (counter % 2);
		m_sourceRectangle.y = 54 + m_sourceRectangle.h + 54;
	}*/
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean() {
	std::cout << "cleaning game" << std::endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
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

		// init bmp
		TheTextureManager::Instance()->load("imgs/cat.png", "animate", m_pRenderer);
		/*SDL_Surface* pTempSurface = IMG_Load("imgs/cat.png");

		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

		SDL_FreeSurface(pTempSurface);

		if (m_pTexture == NULL) {
			// error
			std::cout << "Image is not loaded" << std::endl;
			return false;
		}
		else {
			std::cout << "Image is loaded" << std::endl;

			// Set reactangle size 
			SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

			m_sourceRectangle.w = 128;
			m_sourceRectangle.h = 82;
			m_sourceRectangle.y = 54;

			m_destinationRectangle.x = m_sourceRectangle.x = 0;
			m_destinationRectangle.y = 0;
			m_destinationRectangle.w = m_sourceRectangle.w;
			m_destinationRectangle.h = m_sourceRectangle.h;
		}*/
	}

	std::cout << "Init success!" << std::endl;
	m_bRunning = true;
	return true;
}