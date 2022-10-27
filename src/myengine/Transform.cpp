#include "Transform.h"

namespace myengine
{

	Transform::Transform()
	{
		_model_matrix = glm::mat4{ 1.0f };
		_position = glm::vec3(0.0f, 0.0f, 0.0f);
		_rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	}

	void Transform::OnTick()
	{
		_model_matrix = glm::mat4{ 1.0f };

		_model_matrix = glm::translate(_model_matrix, _position);
		_model_matrix = glm::rotate(_model_matrix, glm::radians(1.0f), _rotation);
	}

}