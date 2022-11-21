#include "Transform.h"

namespace myengine
{

	Transform::Transform()
	{
		_position = glm::vec3(0.0f, 0.0f, 0.0f);
		_rotation = glm::vec3(0.0f, 1.0f, 0.0f);
		_scale = glm::vec3(1.0f, 1.0f, 1.0f);
	}

	glm::mat4 Transform::getModelMatrix()
	{
		glm::mat4 rtn = glm::mat4{ 1.0f };
		rtn = glm::translate(rtn, _position);
		rtn = glm::rotate(rtn, glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		rtn = glm::rotate(rtn, glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		rtn = glm::rotate(rtn, glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));

		return rtn;
	}

}