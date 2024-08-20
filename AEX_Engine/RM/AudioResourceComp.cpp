#include "AudioResourceComp.h"


void AudioResourceComp::Load(std::string filepath)
{
	data = AEAudioLoadMusic(filepath.c_str());

	counter++;
}

void AudioResourceComp::Unload()
{
	AEAudioUnloadAudio(data);

	counter--;
}

void* AudioResourceComp::GetData()
{
	return &data;
}
