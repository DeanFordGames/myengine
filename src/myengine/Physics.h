#pragma once

#include "btBulletDynamicsCommon.h"

#include <memory>
#include <rend/rend.h>

namespace myengine
{
	struct Physics
	{
		Physics();

		void tick();

		btVector3 convertVectorTobt(glm::vec3 _vec);
		glm::vec3 convertbtToVector(btVector3 _bt);

		std::shared_ptr<btDiscreteDynamicsWorld> m_world;
	private:
	};
}