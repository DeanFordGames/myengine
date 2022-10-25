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

			m_components.push_back(rtn);

			return rtn;
		}

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

		friend struct Core;
	};

}