#include "Enemy.hpp"



Enemy::Enemy(const LoadParams* pParams) : SDLGameObject(pParams) {
}


Enemy::~Enemy()
{
}


void Enemy::draw() {
	SDLGameObject::draw();
}

void Enemy::update() {
	m_y += 1;
	m_x += 1;
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Enemy::clear() {

}