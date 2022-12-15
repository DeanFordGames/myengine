#include "Component.h"

#include <memory>
#include <AL/al.h>
#include <AL/alc.h>

namespace myengine
{
	struct Audio;

	struct SoundSource : Component
	{

		SoundSource();
		void setAudio(std::shared_ptr<Audio> _audio);

	private:

		void onTick();

		ALuint sourceId;

	};

}