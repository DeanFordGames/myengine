#include <myengine/myengine.h>

using namespace myengine;

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	return 0;
}