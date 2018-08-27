#include "Player.hpp"

Player::Player()  {
}


Player::~Player()
{
}


void Player::draw() {
	SDLGameObject::draw();
}

void Player::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % 4);

	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();

	SDLGameObject::update();
}

void Player::clean() {

}

void Player::load(const LoadParams * pParams) {
	SDLGameObject::load(pParams);
}

void Player::handleInput() {
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();

	m_velocity = *target - m_position;
	m_velocity /= 50;
}