#include "Component.h"

#include <rend/rend.h>

namespace myengine
{
	struct Transform : Component
	{
		Transform();

		glm::mat4 GetModelMatrix() { return _model_matrix; }

		glm::vec3 GetPosition() { return _position; }
		void SetPosition(glm::vec3 _pos) { _position = _pos; }

		float GetPositionX() { return _position.x; }
		void SetPositionX(float _x) { _position.x = _x; }

		float GetPositionY() { return _position.y; }
		void SetPositionY(float _y) { _position.y = _y; }

		float GetPositionZ() { return _position.z; }
		void SetPositionZ(float _z) { _position.z = _z; }


		glm::vec3 GetRotation() { return _rotation; }
		void SetRotaion(glm::vec3 _rot) { _rotation = _rot; }

		float GetRotationX() { return _rotation.x; }
		void SetRotationX(float _x) { _rotation.x = _x; }

		float GetRotationY() { return _rotation.y; }
		void SetRotationY(float _y) { _rotation.y = _y; }

		float GetRotationZ() { return _rotation.z; }
		void SetRotationZ(float _z) { _rotation.z = _z; }


	private:
		glm::mat4 _model_matrix;
		glm::vec3 _position;
		glm::vec3 _rotation;

		void OnTick();
	};
}