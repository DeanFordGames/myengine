#include "Core.h"

namespace myengine
{
	std::shared_ptr<Core> Core::initialize()
	{
		// Core* rtn = new Core - with smarts
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		return rtn;
	}

}