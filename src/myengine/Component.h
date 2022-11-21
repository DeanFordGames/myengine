#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>

#include "Entity.h"
#include "Enviroment.h"
#include "Keyboard.h"
#include "Core.h"

namespace myengine
{

	struct Component
	{
		std::shared_ptr<Entity> getEntity() { return m_entity.lock(); }
		std::shared_ptr<Core> getCore() { return m_entity.lock()->getCore(); }
		std::shared_ptr<Enviroment> getEnviroment() { return getCore()->getEnviroment(); }
		std::shared_ptr<Keyboard> getKeyboard() { return getCore()->getKeyboard(); }



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