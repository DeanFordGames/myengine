#include <myengine/myengine.h>
#include <iostream>

using namespace myengine;

struct Player : Component
{
	void onTick()
	{
		std::cout << "Ticking" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> e = core->addEntity();
	e->addComponent<Transform>();
	e->addComponent<Player>();
	e->addComponent<TriangleRenderer>();
	e->addComponent<SoundSource>();

	core->start();

	return 0;
}