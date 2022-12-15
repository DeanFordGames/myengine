#include "Resource.h"

#include <memory>
#include <vector>
#include <string>

namespace myengine
{
	struct Resources
	{

		template <typename T>
		std::shared_ptr<T> load(const std::string& _path);

	private:

		std::vector<std::shared_ptr<Resource>> m_resources;
	};
}