#pragma once
#include <vector>
#include <SDL2/SDL_keycode.h>
#include <iostream>

namespace myengine
{
	enum class KeyCodes {
		zero = SDLK_0, one = SDLK_1, two = SDLK_2,
		three = SDLK_3, four = SDLK_4, five = SDLK_5,
		six = SDLK_6, seven = SDLK_7, eight = SDLK_8,
		nine = SDLK_9,

		a = SDLK_a, b = SDLK_b, c = SDLK_c, d = SDLK_d, e = SDLK_e, f = SDLK_f,
		g = SDLK_g, h = SDLK_h, i = SDLK_i, j = SDLK_j, k = SDLK_k, l = SDLK_l,
		m = SDLK_m, n = SDLK_n, o = SDLK_o, p = SDLK_p, q = SDLK_q, r = SDLK_r,
		s = SDLK_s, t = SDLK_t, u = SDLK_u, v = SDLK_v, w = SDLK_w, x = SDLK_x,
		y = SDLK_y, z = SDLK_z,

		escape = SDLK_ESCAPE, lshift = SDLK_LSHIFT,
		rshift = SDLK_RSHIFT, lctrl = SDLK_LCTRL,
		rctrl = SDLK_RCTRL, left = SDLK_LEFT, 
		up = SDLK_UP, down = SDLK_DOWN, 
		right = SDLK_RIGHT, enter = SDLK_RETURN
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