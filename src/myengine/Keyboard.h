#pragma once
#include <vector>
#include <SDL2/SDL_keycode.h>
#include <iostream>

namespace myengine
{
	/**
	* KeyCodes enum for all the keycodes 
	*/
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
		right = SDLK_RIGHT, enter = SDLK_RETURN,
		backspace = SDLK_BACKSPACE, tab = SDLK_TAB,
		space = SDLK_SPACE, exclaim = SDLK_EXCLAIM,
		quotedbl = SDLK_QUOTEDBL, hash = SDLK_HASH,
		percent = SDLK_PERCENT, dollar = SDLK_DOLLAR,
		ampersand = SDLK_AMPERSAND, quote = SDLK_QUOTE,
		leftParen = SDLK_LEFTPAREN, rightParen = SDLK_RIGHTPAREN, 
		asterisk = SDLK_ASTERISK, plus = SDLK_PLUS,
		comma = SDLK_COMMA, minus = SDLK_MINUS,
		period = SDLK_PERIOD, slash = SDLK_SLASH,
		colon = SDLK_COLON, semiColon = SDLK_SEMICOLON,
		lessThan = SDLK_LESS, greaterThan = SDLK_GREATER,
		question = SDLK_QUESTION, at = SDLK_AT,
		leftBracket = SDLK_LEFTBRACKET, rightBracket = SDLK_RIGHTBRACKET,
		backSlash = SDLK_BACKSLASH, caret = SDLK_CARET,
		underscore = SDLK_UNDERSCORE, backQuote = SDLK_BACKQUOTE,
	};


	struct Keyboard
	{
		Keyboard();

		/**
		* getKeyDown set key as down
		* \param key keycode for what key has been pressed
		*/
		void getKeyDown(int key){ m_keys[key] = true; }
		/**
		* getKeyUp set key as up
		* \param key keycode for what key has been pressed
		*/
		void getKeyUp(int key){ m_keys[key] = false; }
		/**
		* getKey returns a keycode if its true or false
		* \param keyCode
		* \return true or false if key is pressed down
		*/
		bool getKey(KeyCodes keyCode) { return m_keys[int(keyCode)]; }

	private:

		bool m_keys[322]; ///< array of bool checks for each key

	};
}