#pragma once
#include "SDLGameObject.hpp"
#include "InputHandler.hpp"
#include "GameObjectFactory.hpp"

class MenuButton : public SDLGameObject
{
public:
	MenuButton();

	virtual void draw();
	virtual void update();
	virtual void clean();

	virtual void load(const LoadParams* pParams) override;

	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() const { return m_callbackID; }

private:

	void(*m_callback) ();
	bool m_bReleased;

	enum button_state {
		MOUSE_OUT,
		MOUSE_OVER,
		CLICKED
	};
};

class MenuButtonCreator : public BaseCreator
{
	virtual GameObject* createGameObject() const {
		return new MenuButton();
	}
};