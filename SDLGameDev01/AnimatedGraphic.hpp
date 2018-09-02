#pragma once

#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"

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

class AnimatedGraphicCreator : public BaseCreator
{
	virtual GameObject* createGameObject() const {
		return new AnimatedGraphic();
	}
};