#include "RigidBody.h"

#include "BoxCollider.h"
#include "Core.h"

#include <list>

namespace myengine
{

	void RigidBody::onTick()
	{
		std::vector<std::shared_ptr<BoxCollider>> box;

		getCore()->find(box);

		for (std::vector<std::shared_ptr<BoxCollider>>::iterator it = box.begin();
			it != box.end(); ++it)
		{
			if ((*it) != getEntity()->getComponent<BoxCollider>())
			{
				getEntity()->getComponent<BoxCollider>()->colliding((**it));
			}
		}
	}

}