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

	//first entity

	std::shared_ptr<Entity> e = core->addEntity();
	e->addComponent<Transform>();
	e->addComponent<Player>();
	std::shared_ptr<TriangleRenderer> tr = e->addComponent<TriangleRenderer>();
	tr->setTexture(core->getResources()->load<Texture>("dirt.jpg"));

	std::shared_ptr<SoundSource> audio = e->addComponent<SoundSource>();
	audio->setAudio(core->getResources()->load<Audio>("bfg.ogg"));

	std::shared_ptr<BoxCollider> bc1 = e->addComponent<BoxCollider>();
	bc1->setSize(glm::vec3(0.1f, 0.1f, 0.1f));
	bc1->initialize();
	std::shared_ptr<RigidBody> r1 = e->addComponent<RigidBody>();
	r1->initialize();

	//e->addComponent<IrcComponent>();

	//first entity

	//second entity

	std::shared_ptr<Entity> e2 = core->addEntity();
	std::shared_ptr<Transform> t = e2->addComponent<Transform>();
	t->setPosition(glm::vec3(-0.5f, -0.2f, 0.0f));
	t->setScale(glm::vec3(0.2f, 0.2f, 0.2f));

	std::shared_ptr<ModelRenderer> mr = e2->addComponent<ModelRenderer>();
	mr->setModel(core->getResources()->load<Model>("models/curuthers/curuthers.obj"));
	mr->steTexture(core->getResources()->load<Texture>("models/curuthers/Whiskers_diffuse.png"));

	std::shared_ptr<BoxCollider> bc2 = e2->addComponent<BoxCollider>();
	bc2->setSize(glm::vec3(1.0f, 1.0f, 1.0f));
	bc2->initialize();

	//second entity

	//floor

	std::shared_ptr<Entity> floor = core->addEntity();
	std::shared_ptr<Transform> floorT = floor->addComponent<Transform>();
	floorT->setPosition(glm::vec3(0.0f, -1.0f, 0.0f));
	floorT->setScale(glm::vec3(10.0f, 0.5f, 10.0f));

	std::shared_ptr<ModelRenderer> floorMR = floor->addComponent<ModelRenderer>();
	floorMR->setModel(core->getResources()->load<Model>("models/floor/floor.obj"));
	floorMR->steTexture(core->getResources()->load<Texture>("models/floor/tex.png"));

	std::shared_ptr<BoxCollider> floorBC = floor->addComponent<BoxCollider>();
	floorBC->setSize(floorT->getScale());
	floorBC->initialize();

	std::shared_ptr<RigidBody> floorRB = floor->addComponent<RigidBody>();
	floorRB->setMass(0.0f);
	floorRB->initialize();

	//floor

	core->start();

	return 0;
}