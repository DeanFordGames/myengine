#pragma once

#include <SDL2/SDL.h>

namespace myengine
{
	struct Enviroment
	{
		Enviroment();

		float GetDeltaTime() { return deltaTime; }

		void tick();

	private:

		float deltaTime;
		float lastTime;

	};
}