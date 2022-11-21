#pragma once
#include <vector>
#include <SDL2/SDL_keycode.h>
#include <iostream>

namespace myengine
{
	enum class KeyCodes {
		w = SDLK_w
	};

	struct Keyboard
	{
		Keyboard();

		void getKeyDown(int key){ m_keys[key] = true; }
		void getKeyUp(int key){ m_keys[key] = false; }
		bool getKey(KeyCodes keyCode) { return m_keys[int(keyCode)]; }

	private:

		bool m_keys[322];

	};
}