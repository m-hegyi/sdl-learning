#pragma once

#include <SDL.h>

class Game
{
public:
	Game();
	~Game();

	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int heigth, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
};
