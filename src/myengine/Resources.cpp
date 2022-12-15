#include "Resources.h"

namespace myengine
{

	template <typename T>
	std::shared_ptr<T> Resources::load(const std::string& _path)
	{
		for (auto it = m_resources.begin(); it != m_resources.end(); it++)
		{
			if ((*it).m_path == _path)
			{
				return (*it);
			}
		}

		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->m_path = _path;
		rtn->load();
		m_resources(rtn);

		return rtn;
	}

}