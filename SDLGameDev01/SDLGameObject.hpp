#pragma once

#include "GameObject.hpp"
#include "Vector2D.hpp"

class SDLGameObject : public GameObject
{
public:

	SDLGameObject(const LoadParams* pParams);
	~SDLGameObject();

	virtual void draw();
	virtual void update();
	virtual void clean();
	
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	
	int m_width;
	int m_height;
	
	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};

