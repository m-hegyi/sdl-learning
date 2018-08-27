#pragma once

#include "SDLGameObject.hpp"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic();

	virtual void draw();
	virtual void update();
	virtual void clean();

	virtual void load(const LoadParams* pParams) override;

private:
	int m_animSpeed;
};

