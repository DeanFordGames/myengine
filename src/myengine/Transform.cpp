#include "Transform.h"

namespace myengine
{

	Transform::Transform()
	{
		_position = glm::vec3(0.0f, 0.0f, 0.0f);
		_rotation = glm::vec3(0.0f, 1.0f, 0.0f);
		_scale = glm::vec3(1.0f, 1.0f, 1.0f);
	}


}