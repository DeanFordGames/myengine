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

		t->changeRotation(glm::vec3(100.0f, 100.0f, 100.0f) * getCore()->getEnviroment()->GetDeltaTime());

		if (getKeyboard()->getKey(KeyCodes::w))
		{
			std::cout << "wwww" << std::endl;
		}

		r.model(t->getModelMatrix());

		r.shader(&m_shader);
		r.mesh(&m_mesh);

		r.render();
	}

}