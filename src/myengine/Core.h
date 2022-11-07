#include <memory>
#include <list>
#include <SDL2/SDL.h>

#include "Keyboard.h"
#include "Enviroment.h"

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


	private:
		bool m_running;
		std::list<std::shared_ptr<Entity> > m_entities;
		std::shared_ptr<Keyboard> m_keyboard;
		std::shared_ptr<Enviroment> m_enviroment;

		std::weak_ptr<Core> m_self;


		SDL_Window* m_window;
		SDL_GLContext m_context;
	};

}