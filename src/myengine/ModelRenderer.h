#include "Component.h"

#include <memory>
#include <rend/rend.h>
#include <string>

namespace myengine
{
	struct ModelRenderer : Component
	{
		ModelRenderer(const std::string& _path);

	private:
		rend::Model m_model;

		void onDisplay();
	};
}