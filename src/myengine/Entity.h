#ifndef MYENGINE_ENTITY_H
#define MYENGINE_ENTITY_H


#include <memory>
#include <vector>
#include <stdexcept>

namespace myengine
{
	struct Component;
	struct Core;

	struct Entity
	{
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_entity = m_self;
			m_components.push_back(rtn);

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (std::vector<std::shared_ptr<Component>>::iterator it = m_components.begin();
				it != m_components.end(); ++it)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>((*it));
				if (rtn)
				{
					return rtn;
				}
			}
			throw std::runtime_error("Specified component not found");
			
		}

		std::shared_ptr<Core> getCore() { return m_core.lock(); }

		Entity() { 
			m_alive = true; 
		}

		bool alive() { return m_alive; }

		void tick();
		void display();
		void kill();

	private:
		std::vector<std::shared_ptr<Component> > m_components;

		bool m_alive;

		std::weak_ptr<Entity> m_self;
		std::weak_ptr<Core> m_core;

		friend struct Core;
	};

}

#endif