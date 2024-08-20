#pragma once

#include "BaseComponent.h"
#include <string>
#include "AEAudio.h"

class AudioComponent : public BaseComponent
{
	AEAudioGroup mGroup;
	AEAudio mAudio;

public:

	float volume = 0.25f;
	float pitch = 1;

	bool loop = true;
	bool Playing = false;

	AudioComponent(GameObject* owner);
	~AudioComponent();
	void Update() override;

	json SaveToJson() override { return json{}; };
	void LoadFromJson(const json&) override {};

	void SetAudio(std::string s);
	void SetAudio(AEAudio s);
};