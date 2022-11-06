#include "TriangleRenderer.h"
#include "Transform.h"
#include "Entity.h"

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

		std::shared_ptr<Transform> t = GetEntity()->getComponent<Transform>();

		t->ChangeRotation(glm::vec3(0.1f, 0.0f, 0.0f));

		r.model(t->GetModelMatrix());

		r.shader(&m_shader);
		r.mesh(&m_mesh);

		r.render();
	}

}