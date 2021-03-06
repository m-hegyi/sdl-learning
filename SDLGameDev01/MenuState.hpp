#pragma once
#include <vector>

#include "TextureManager.hpp"
#include "Game.hpp"
#include "SDLGameObject.hpp"
#include "GameState.hpp"

class MenuState : public GameState
{
protected: 
	MenuState() {};
	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;

	std::vector<Callback> m_callbacks;
private:
};