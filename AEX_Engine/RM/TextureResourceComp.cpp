#include "TextureResourceComp.h"

void TextureResourceComp::Load(std::string filepath)
{
	data = AEGfxTextureLoad(filepath.c_str());
	counter++;
}

void TextureResourceComp::Unload()
{
	AEGfxTextureUnload(data);

	counter--;
}

void* TextureResourceComp::GetData()
{
	return data;
}
