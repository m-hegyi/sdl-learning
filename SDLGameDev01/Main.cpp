#include "Game.hpp"
#include <iostream>

// Game object
//Game* g_Game = 0;

int main(int argc, char* args[]) {

	std::cout << "Game init attempt..." << std::endl;

	if (Game::Instance()->init("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false)) {
		std::cout << "Game init success!" << std::endl;
		while (Game::Instance()->running()) {
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			SDL_Delay(10);
		}
	}
	else {
		std::cout << "Game init failed!" << std::endl;
		return 0;
	}

	std::cout << "The game closing..." << std::endl;
	Game::Instance()->clean();

	return 0;
	
	//g_Game = new Game();

	//g_Game->init("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	//while (g_Game->running()) {
		//g_Game->handleEvents();
		//g_Game->update();
		//g_Game->render();

		//SDL_Delay(10);
	//}

	//g_Game->clean();
}