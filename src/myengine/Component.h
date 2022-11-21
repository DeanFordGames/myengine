#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>

namespace myengine
{
	struct Entity;
	struct Core;

	struct Component
	{
		std::shared_ptr<Entity> getEntity() { return m_entity.lock(); }


	private:
		virtual void onTick();
		virtual void onDisplay();

		void tick();
		void display();

		friend struct Entity;


		std::weak_ptr<Entity> m_entity;
	};
}

#endif