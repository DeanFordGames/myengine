#include "Component.h"

#include <rend/rend.h>

namespace myengine
{

	struct BoxCollider : Component
	{
		bool colliding(BoxCollider& _other);

		glm::vec3 getSize() { return m_size; }
		void setSize(glm::vec3 size) { m_size = size; }
		void changeSize(glm::vec3 size) { m_size += size; }

		glm::vec3 getOffset() { return m_offset; }
		void setOffset(glm::vec3 offset) { m_offset = offset; }
		void changeOffset(glm::vec3 offset) { m_offset += offset; }

	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;
	};

}