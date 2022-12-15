#include "SoundSource.h"
#include "Transform.h"
#include "Entity.h"
#include "Audio.h"

#include <stdexcept>
#include <vector>
#include <string>

namespace myengine
{

	SoundSource::SoundSource()
	{
		/*************************************************************************
		 * Preparing sound source
		 *************************************************************************/
		sourceId = 0;
		alGenSources(1, &sourceId);
	}

	void SoundSource::onTick()
	{
		std::shared_ptr<Transform> t = getEntity()->getComponent<Transform>();

		glm::vec3 pos = t->getPosition();

		alSource3f(sourceId, AL_POSITION, pos.x, pos.y, pos.z);
	}


	void SoundSource::setAudio(std::shared_ptr<Audio> _audio)
	{
		alSourcei(sourceId, AL_BUFFER, _audio->m_id);

		//alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcef(sourceId, AL_PITCH, 1.0);
		//alSourcef(sourceId, AL_GAIN, vol);

		/*************************************************************************
		 * Play audio
		 *************************************************************************/
		alSourcePlay(sourceId);
	}
}