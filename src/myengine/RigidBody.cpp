#include "RigidBody.h"

#include "BoxCollider.h"
#include "Core.h"
#include "Transform.h"

#include <list>
#include <memory>

namespace myengine
{
	RigidBody::RigidBody()
	{
		m_transform.setIdentity();
		m_mass = 1.0f;
	}

	void RigidBody::initialize()
	{
		m_transform.setOrigin(getPhysics()->convertVectorTobt(getEntity()->getComponent<Transform>()->getPosition()));
		btVector3 localInertia(0, 0, 0);

		if(m_mass != 0.0f)
			getEntity()->getComponent<BoxCollider>()->getCollider()->calculateLocalInertia(m_mass, localInertia);

		btDefaultMotionState* motionState = new btDefaultMotionState(m_transform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(m_mass, motionState, getEntity()->getComponent<BoxCollider>()->getCollider().get(), localInertia);
		m_body = std::make_shared<btRigidBody>(rbInfo);

		getPhysics()->m_world->addRigidBody(m_body.get());
	}

	void RigidBody::onTick()
	{
		m_transform = m_body->getWorldTransform();
		getEntity()->getComponent<Transform>()->setPosition(getPhysics()->convertbtToVector(m_transform.getOrigin()));
	}

	//std::vector<std::shared_ptr<BoxCollider>> box;

//getCore()->find(box);

//for (std::vector<std::shared_ptr<BoxCollider>>::iterator it = box.begin();
//	it != box.end(); ++it)
//{
//	if ((*it) != getEntity()->getComponent<BoxCollider>())
//	{
//		if (getEntity()->getComponent<BoxCollider>()->colliding((**it)))
//		{
//			std::shared_ptr<Transform> t = getEntity()->getComponent<Transform>();
//			t->setPosition(glm::vec3(1.0f, 1.0f, 0.0f));
//		}
//	}
//}

}