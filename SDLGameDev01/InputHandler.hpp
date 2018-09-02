#pragma once
#include <SDL.h>
#include <vector>

#include "Vector2D.hpp"
#include "Game.hpp"

enum mouse_buttons {
	LEFT,
	MIDDLE,
	RIGHT
};

class InputHandler
{
public:
	static InputHandler* Instance() {
		if (s_pInstance == NULL) {
			s_pInstance = new InputHandler();
			return s_pInstance;
		}
		return s_pInstance;
	}

	void update();
	void clean();

	// mouse
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition() { return m_mousePosition; };

	// keyboard
	bool isKeyDown(SDL_Scancode key);

	// jostick
	void initializeJoysticks();
	bool joysticksInitialised() {
		return m_bJoysticksInitialized;
	}

	bool getButtonState(int joy, int buttonNumber);

	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	~InputHandler() {};
	void reset();

private:
	InputHandler();

	static InputHandler* s_pInstance;

	// handle keyboard events
	void onKeyDown();
	void onKeyUp();

	// handle mouse events
	void onMouseMove(SDL_Event &event);
	void onMouseButtonDown(SDL_Event &event);
	void onMouseButtonUp(SDL_Event &event);

	// handle joystick events
	void onJoystickAxisMove(SDL_Event &event);
	void onJoystickButtonDown(SDL_Event &event);
	void onJoystickButtonUp(SDL_Event &event);

private:

	// mouse
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition = new Vector2D(0, 0);

	// keyboard
	const Uint8* m_keystate;

	// joystick
	const int m_joystickDeadZone = 1000;
	std::vector<std::vector<bool>> m_buttonStates;

	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	bool m_bJoysticksInitialized;
};

typedef InputHandler TheInputHandler;