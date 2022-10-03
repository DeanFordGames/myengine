#include <memory>

struct Core
{
	static std::shared_ptr<Core> initialize();

private:
	int m_dummy;
};