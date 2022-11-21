#include "TriangleRenderer.h"
#include "Transform.h"
#include "Entity.h"

#include <iostream>

namespace myengine
{

	TriangleRenderer::TriangleRenderer() :
		m_shader("../data/shaders/basic.vert", "../data/shaders/basic.frag")
	{
		m_mesh.loadQuad();
	}

	void TriangleRenderer::onDisplay()
	{
		rend::Renderer r(640, 480);

		std::shared_ptr<Transform> t = getEntity()->getComponent<Transform>();

		t->changeRotation(glm::vec3(100.0f, 100.0f, 100.0f) * getEnviroment()->GetDeltaTime());

		if (getKeyboard()->getKey(KeyCodes::w))
		{
			t->changePosition(glm::vec3(0.0f, 1.0f, 0.0f) * getEnviroment()->GetDeltaTime());
		}
		if (getKeyboard()->getKey(KeyCodes::s))
		{
			t->changePosition(glm::vec3(0.0f, -1.0f, 0.0f) * getEnviroment()->GetDeltaTime());
		}
		if (getKeyboard()->getKey(KeyCodes::a))
		{
			t->changePosition(glm::vec3(-1.0f, 0.0f, 0.0f) * getEnviroment()->GetDeltaTime());
		}
		if (getKeyboard()->getKey(KeyCodes::d))
		{
			t->changePosition(glm::vec3(1.0f, 0.0f, 0.0f) * getEnviroment()->GetDeltaTime());
		}

		r.model(t->getModelMatrix());

		r.shader(&m_shader);
		r.mesh(&m_mesh);

		r.render();
	}

}