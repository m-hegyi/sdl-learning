#include "Game.hpp"
#include <iostream>

// Game object
Game* g_Game = 0;

int main(int argc, char* args[]) {
	
	g_Game = new Game();

	g_Game->init("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (g_Game->running()) {
		g_Game->handleEvents();
		g_Game->update();
		g_Game->render();
	}

	g_Game->clean();

	return 0;
}