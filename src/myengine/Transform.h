#include "Component.h"

#include <rend/rend.h>

namespace myengine
{
	/**
	* Component provideing the positional values for the entity 
	*/
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

		/**
		* creates the required model matrix for the entity
		* \return created model matrix
		*/
		glm::mat4 getModelMatrix();


	private:
		glm::vec3 _position; ///< x, y, z position of entity
		glm::vec3 _rotation; ///< rotation of entity in euler angles
		glm::vec3 _scale; ///< scale of entity

		glm::mat4 _matrix; ///< model matrix for transform

		bool m_dirty; ///< check if any matrix value needs to change

	};
}