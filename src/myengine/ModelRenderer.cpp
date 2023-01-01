#include "ModelRenderer.h"

namespace myengine
{
	ModelRenderer::ModelRenderer(const std::string& _path) :
		m_model(_path.c_str())
	{
	}

	void ModelRenderer::onDisplay()
	{
		rend::ModelRenderer r(640, 640);
	}
}