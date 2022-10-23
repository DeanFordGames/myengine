#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

namespace myengine
{
	struct Entity;

	struct Component
	{
	private:
		virtual void onTick();
		virtual void onDisplay();

		void tick();
		void display();

		void kill();

		friend struct Entity;
	};
}

#endif