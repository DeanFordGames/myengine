#include "Component.h"

#include <rend/rend.h>

namespace myengine
{
	struct Transform : Component
	{
		Transform();

		void changePosition(glm::vec3 _pos) { _position += _pos; }
		glm::vec3 getPosition() { return _position; }
		void setPosition(glm::vec3 _pos) { _position = _pos; }

		void changeRotation(glm::vec3 _rot) { _rotation += _rot; }
		glm::vec3 getRotation() { return _rotation; }
		void setRotaion(glm::vec3 _rot) { _rotation = _rot; }

		glm::vec3 getScale() { return _scale; }
		void setScale(glm::vec3 _s) { _scale = _s; }
		void changeScale(glm::vec3 _s) { _scale += _s; }

		glm::mat4 getModelMatrix();


	private:
		glm::vec3 _position;
		glm::vec3 _rotation;
		glm::vec3 _scale;

	};
}