#include "Core.h"
#include "Entity.h"

#include<stdexcept>


namespace myengine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		rtn->m_self = rtn;
		rtn->m_running = false;

		rtn->m_enviroment = std::make_shared<Enviroment>();
		rtn->m_keyboard = std::make_shared<Keyboard>();

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		if (!(rtn->m_window = SDL_CreateWindow("SLD2 Platform",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			INITIAL_WIDTH, INITIAL_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)))
		{
			SDL_Quit();
			throw std::runtime_error("Failed to create window");
		}

		if (!(rtn->m_context = SDL_GL_CreateContext(rtn->m_window)))
		{
			SDL_DestroyWindow(rtn->m_window);
			SDL_Quit();
			throw std::runtime_error("Failed to create OpenGl context");
		}

		return rtn;
	}

	Core::~Core()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	void Core::start()
	{
		SDL_Event event = { 0 };
		m_running = true;

		while (m_running)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					m_running = false;
				}
				else if (event.type = SDL_KEYDOWN)
				{

				}
			}

			m_enviroment->tick();

			for (auto it = m_entities.begin(); //auto = std::list<std::shared_ptr<Entity> >::iterator
				it != m_entities.end(); ++it)
			{
				(*it)->tick();
			}

			auto itr = m_entities.begin();
			while (itr != m_entities.end())
			{
				if ((*itr)->alive())
				{
					itr++;
				}
				else
				{
					itr = m_entities.erase(itr);
				}
			}


			rend::Renderer r(INITIAL_WIDTH, INITIAL_HEIGHT);
			r.clear();

			for (auto it = m_entities.begin(); //auto = std::list<std::shared_ptr<Entity> >::iterator
				it != m_entities.end(); ++it)
			{
				(*it)->display();
			}

			SDL_GL_SwapWindow(m_window);
		}
	}

	void Core::stop()
	{
		m_running = false;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_self = rtn;

		m_entities.push_back(rtn);

		return rtn;
	}

}