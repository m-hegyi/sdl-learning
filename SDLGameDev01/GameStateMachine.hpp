#pragma once
#include <vector>

#include "GameState.hpp"

class GameStateMachine
{
public:

	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();

private:
	std::vector<GameState*> m_gameStates;

};

