#pragma once
#include <vector>

namespace myengine
{
	struct Keyboard
	{
		Keyboard();

	private:

		std::vector<int> m_keyCodes;

	};
}