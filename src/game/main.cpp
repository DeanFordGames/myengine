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
	std::shared_ptr<TriangleRenderer> tr = e->addComponent<TriangleRenderer>();
	tr->setTexture(core->getResources()->load<Texture>("dirt.jpg"));

	std::shared_ptr<SoundSource> audio = e->addComponent<SoundSource>();
	audio->setAudio(core->getResources()->load<Audio>("bfg.ogg"));

	e->addComponent<IrcComponent>();

	core->start();

	return 0;
}