#include "Player.hpp"

Player::Player(const LoadParams* pParams) : SDLGameObject(pParams) {
}


Player::~Player()
{
}


void Player::draw() {
	SDLGameObject::draw();
}

void Player::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);

	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();

	SDLGameObject::update();
}

void Player::clean() {

}

void Player::handleInput() {
	// mouse
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	m_velocity = (*vec - m_position) / 100;

	// keyboard
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_velocity.setY(2);
	}

	// joystick
	if (TheInputHandler::Instance()->joysticksInitialised()) {
		if (TheInputHandler::Instance()->xvalue(0, 1) > 0 || TheInputHandler::Instance()->xvalue(0, 1) < 0) {
			m_velocity.setX((float)1 * TheInputHandler::Instance()->xvalue(0, 1));
		}
		if (TheInputHandler::Instance()->yvalue(0, 1) > 0 || TheInputHandler::Instance()->yvalue(0, 1) < 0) {
			m_velocity.setY((float)1 * TheInputHandler::Instance()->yvalue(0, 1));
		}
		if (TheInputHandler::Instance()->xvalue(0, 2) > 0 || TheInputHandler::Instance()->xvalue(0, 2) < 0) {
			m_velocity.setX((float)1 * TheInputHandler::Instance()->xvalue(0, 1));
		}
		if (TheInputHandler::Instance()->yvalue(0, 2) > 0 || TheInputHandler::Instance()->yvalue(0, 2) < 0) {
			m_velocity.setY((float)1 * TheInputHandler::Instance()->yvalue(0, 1));
		}
		if (TheInputHandler::Instance()->getButtonState(0, 3)) {
			m_velocity.setX(1);
		}
	}
}