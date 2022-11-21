#include "Transform.h"

namespace myengine
{

	Transform::Transform()
	{
		_position = glm::vec3(0.0f, 0.0f, 0.0f);
		_rotation = glm::vec3(0.0f, 1.0f, 0.0f);
		_scale = glm::vec3(1.0f, 1.0f, 1.0f);
		_matrix = glm::mat4{ 1.0f };
		m_dirty = false;
	}

	glm::mat4 Transform::getModelMatrix()
	{
		if (m_dirty == true)
		{
			_matrix = glm::mat4{ 1.0f };
			_matrix = glm::translate(_matrix, _position);
			_matrix = glm::rotate(_matrix, glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
			_matrix = glm::rotate(_matrix, glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
			_matrix = glm::rotate(_matrix, glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
			m_dirty = false;
		}

		return _matrix;
	}

}