#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "TextureManager.hpp"
#include "InputHandler.hpp"
#include "AnimatedGraphic.hpp"
#include "GameStateMachine.hpp"

class Game
{
public:
	static Game* Instance() {
		if (s_pInstance == NULL) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	Game();
	static Game* s_pInstance;
public:
	~Game();
	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int heigth, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();

	bool running() { return m_bRunning; }

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	GameStateMachine* getStateMache() { return m_pGameStateMachine; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	bool m_bRunning;

	std::vector<GameObject*> m_gameObjects;

	GameStateMachine* m_pGameStateMachine;
};

	typedef Game TheGame;
