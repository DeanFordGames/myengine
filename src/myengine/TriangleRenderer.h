#include "Component.h"

#include <memory>
#include<rend/rend.h>

namespace myengine
{
	struct Texture;

	struct TriangleRenderer : Component
	{
		TriangleRenderer();

		void setTexture(std::shared_ptr<Texture> _texture);

	private:
		rend::Mesh m_mesh;
		rend::Shader m_shader;
		std::shared_ptr<Texture> m_texture;

		void onDisplay();
	};

}