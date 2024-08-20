#pragma once

#include "AEEngine.h"
#include "Resource.h"

class TextureResourceComp : public Resource
{
	//AEGfxTexture* Tex = static_cast<AEGfxTexture*>(data);
public:
	AEGfxTexture* data;
	
	void* GetData() override;
	//pure virtual fn to LOAD data
	void Load(std::string filepath) override;
	//pure virtual fn to UNLOAD data
	void Unload() override;
};