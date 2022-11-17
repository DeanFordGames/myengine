#include "Component.h"

#include <AL/al.h>
#include <AL/alc.h>

namespace myengine
{

	struct SoundSource : Component
	{

		SoundSource();

	private:

		void onTick();

		ALuint sourceId;

	};

}