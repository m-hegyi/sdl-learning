#pragma once
#include "SDLGameObject.hpp"
#include "InputHandler.hpp"

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoadParams* pParams, void (*callback) ());

	virtual void draw();
	virtual void update();
	virtual void clean();

private:

	void(*m_callback) ();
	bool m_bReleased;

	enum button_state {
		MOUSE_OUT,
		MOUSE_OVER,
		CLICKED
	};
};

