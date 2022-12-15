#ifndef MYENGINE_CORE_H
#define MYENGINE_CORE_H

#include <memory>
#include <list>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>

#include "Keyboard.h"
#include "Enviroment.h"
#include "Resources.h"

#include <rend/rend.h>

#define INITIAL_HEIGHT 480
#define INITIAL_WIDTH 640

namespace myengine
{
	struct Entity;

	struct Core
	{
		static std::shared_ptr<Core> initialize();

		~Core();

		void start();
		void stop();

		std::shared_ptr<Entity> addEntity();

		std::shared_ptr<Enviroment> getEnviroment() { return m_enviroment; }
		std::shared_ptr<Keyboard> getKeyboard() { return m_keyboard; }
		std::shared_ptr<Resources> getResources() { return m_resources; }

		template <typename T>
		void find(std::vector<std::shared_ptr<T>>& _out);

	private:
		bool m_running;
		std::list<std::shared_ptr<Entity> > m_entities;
		std::shared_ptr<Keyboard> m_keyboard;
		std::shared_ptr<Enviroment> m_enviroment;
		std::shared_ptr<Resources> m_resources;

		std::weak_ptr<Core> m_self;

		SDL_Window* m_window;
		SDL_GLContext m_context;
	};

}

#endif // !MYENGINE_CORE_H