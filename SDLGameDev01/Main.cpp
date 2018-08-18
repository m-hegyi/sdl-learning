#include "Game.hpp"
#include <iostream>

const int FPS = 60;
const int DELAY_TIME = (int)(1000.0f / FPS);

int main(int argc, char* args[]) {

	Uint32 frameStart, frameTime;

	std::cout << "Game init attempt..." << std::endl;

	if (Game::Instance()->init("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false)) {
		std::cout << "Game init success!" << std::endl;
		while (Game::Instance()->running()) {
			frameStart = SDL_GetTicks();

			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME) {
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
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