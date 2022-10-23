#include "Entity.h"
#include "Component.h"

namespace myengine
{
	void Entity::tick()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = m_components.begin();
			it != m_components.end(); ++it)
		{
			(*it)->tick();
		}
	}

	void Entity::display()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = m_components.begin();
			it != m_components.end(); ++it)
		{
			(*it)->display();
		}
	}

	void Entity::kill()
	{
		if (!m_alive) return;

		m_alive = false;

		for (std::vector<std::shared_ptr<Component>>::iterator it = m_components.begin();
			it != m_components.end(); ++it)
		{
			(*it)->kill();
		}
	}
}