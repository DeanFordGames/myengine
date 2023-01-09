#include "ModelRenderer.h"
#include "Transform.h"
#include "Entity.h"
#include "Model.h"
#include "Texture.h"

namespace myengine
{
	ModelRenderer::ModelRenderer() :
		m_shader("../data/shaders/basic.vert", "../data/shaders/basic.frag")
	{
	}

	void ModelRenderer::onDisplay()
	{
		rend::ModelRenderer r(640, 640);

		std::shared_ptr<Transform> t = getEntity()->getComponent<Transform>();

		r.modelMatrix(t->getModelMatrix());
		r.shader(&m_shader);
		r.texture(m_texture->m_texture.get());
		r.model(m_model->m_model.get());

		r.depthTest(true);

		r.render();

	}

	void ModelRenderer::setModel(std::shared_ptr<Model> _model)
	{
		m_model = _model;
	}

	void ModelRenderer::steTexture(std::shared_ptr<Texture> _texture)
	{
		m_texture = _texture;
	}
}