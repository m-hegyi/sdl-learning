#pragma once

#include "GameObject.hpp"
#include "Vector2D.hpp"

class SDLGameObject : public GameObject
{
public:

	SDLGameObject();
	~SDLGameObject();

	virtual void draw();
	virtual void update();
	virtual void clean();

	virtual void load(const LoadParams* pParams) override;

	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	
	int m_width;
	int m_height;
	
	int m_currentRow;
	int m_currentFrame;
	int m_callbackID;

	int m_numFrames;

	std::string m_textureID;
};

