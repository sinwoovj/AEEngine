#include "AudioComponent.h"
#include "ComponentManager.h"

#include "AEAudio.h"

AudioComponent::AudioComponent(GameObject* owner) : BaseComponent(owner), mGroup(), mAudio()
{
	ComponentManager<AudioComponent>::GetManager()->AddComponent(this);
	mGroup = AEAudioCreateGroup();
}

AudioComponent::~AudioComponent()
{
	ComponentManager<AudioComponent>::GetManager()->RemoveComponent(this);

	AEAudioUnloadAudio(mAudio);
	AEAudioUnloadAudioGroup(mGroup);
}

void AudioComponent::Update()
{
	//Play the audio if it is not playing already

	int loops = 0;
	if (loop)
		loops = -1;
	if (!Playing)
	{
		Playing = true;
		AEAudioPlay(mAudio, mGroup, volume, pitch, loops);
	}
}

void AudioComponent::SetAudio(std::string s)
{
	mAudio = AEAudioLoadMusic(s.c_str());
}


void AudioComponent::SetAudio(AEAudio s)
{
	mAudio = s;
}
