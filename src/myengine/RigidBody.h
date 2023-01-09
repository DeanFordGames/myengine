#include "Component.h"

#include "btBulletDynamicsCommon.h"

namespace myengine
{
	/**
	* Component provides the physics for the Entity 
	*/
	struct RigidBody : Component
	{
		RigidBody();

		void initialize();

		void setMass(float _mass) { m_mass = _mass; }

		/**
		* onTick Update function 
		*/
		void onTick();

	private:
		btTransform m_transform;
		btScalar m_mass;
		std::shared_ptr<btRigidBody> m_body;
	};

}