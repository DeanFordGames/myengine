#include "Component.h"

#include <rend/rend.h>

namespace myengine
{
	struct Transform : Component
	{
		Transform();

		void changePosition(glm::vec3 _pos) { _position += _pos; m_dirty = true; }
		glm::vec3 getPosition() { return _position; }
		void setPosition(glm::vec3 _pos) { _position = _pos; m_dirty = true; }

		void changeRotation(glm::vec3 _rot) { _rotation += _rot; m_dirty = true; }
		glm::vec3 getRotation() { return _rotation; }
		void setRotaion(glm::vec3 _rot) { _rotation = _rot; m_dirty = true; }

		glm::vec3 getScale() { return _scale; }
		void setScale(glm::vec3 _s) { _scale = _s; m_dirty = true; }
		void changeScale(glm::vec3 _s) { _scale += _s; m_dirty = true; }

		glm::mat4 getModelMatrix();


	private:
		glm::vec3 _position;
		glm::vec3 _rotation;
		glm::vec3 _scale;

		glm::mat4 _matrix;

		bool m_dirty;

	};
}