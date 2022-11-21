#include "Keyboard.h"


namespace myengine
{
	Keyboard::Keyboard()
	{
		for (int i = 0; i < 322; i++)
		{
			m_keys[i] = false;
		}
	}
}