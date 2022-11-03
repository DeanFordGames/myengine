#include <memory>
#include <vector>

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

		Entity() { 
			m_alive = true; 
		}

		template <typename T>
		std::shared_ptr<T> getComponent();

		bool alive() { return m_alive; }

		void tick();
		void display();
		void kill();

	private:
		std::vector<std::shared_ptr<Component> > m_components;

		bool m_alive;

		std::weak_ptr<Entity> m_self;

		friend struct Core;
	};

}