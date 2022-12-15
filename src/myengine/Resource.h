#pragma once

#include <string>

namespace myengine
{
	struct Resources;

	struct Resource
	{
		virtual void onLoad() = 0;

		std::string getPath() const { return m_path; };

	private:
		friend struct Resources;

		std::string m_path;

		void load();
	};

}