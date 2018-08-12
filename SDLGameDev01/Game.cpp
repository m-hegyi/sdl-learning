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

	SDL_RenderPresent(m_pRenderer); // Draw the screen
}

void Game::update()
{
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
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
		}
	}

	std::cout << "Init success!" << std::endl;
	m_bRunning = true;
	return true;
}