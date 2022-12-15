#include "Resource.h"

#include <memory>
#include <AL/al.h>

namespace myengine
{
	struct SoundSource;

	struct Audio : Resource
	{
		void onLoad();

	private:
		friend struct SoundSource;

		 ALuint m_id;
	};
}