#include "Resource.h"
#include <rend/rend.h>

#include <memory>

namespace myengine
{
	struct TriangleRenderer;

	struct Texture : Resource
	{
		void onLoad();

	private:
		friend struct TriangleRenderer;

		std::shared_ptr<rend::Texture> m_texture;
	};
}