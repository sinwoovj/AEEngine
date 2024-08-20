#pragma once

#include "AEEngine.h"
#include "Resource.h"

class AudioResourceComp : public Resource
{
	//AEAudio* Aud = static_cast<AEAudio*>(data);

public:
	AEAudio data;

	void* GetData() override;
	//pure virtual fn to LOAD data
	void Load(std::string filepath) override;
	//pure virtual fn to UNLOAD data
	void Unload() override;
};