#pragma once

#include "SDLGameObject.hpp"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoadParams* pParams, int animSpeed);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	int m_animSpeed;
};

