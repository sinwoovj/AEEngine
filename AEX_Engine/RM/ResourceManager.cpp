#include "ResourceManager.h"

ResourceManager* ResourceManager::myResource_ptr = nullptr;
std::unordered_map<std::string, fileExt> const ResourceManager::fileExtmap = { {"png", png},{"mp3", mp3},{"wav", wav},{"jpg", jpg} };

void ResourceManager::Unload(std::string filepath)
{
	if (files.find(filepath) != files.end())
	{
		files.find(filepath)->second->counter--;



		if (files.find(filepath)->second->counter == 0)
		{
			files.find(filepath)->second->Unload();
			delete files.find(filepath)->second;
			files.erase(filepath);
		}
	}
}

void ResourceManager::Unload()
{

	for (auto temp : files)
	{
		temp.second->Unload();
		delete temp.second;
	}
	files.clear();
}

ResourceManager* ResourceManager::GetResourceManager()
{
	if (myResource_ptr == nullptr)
	{
		myResource_ptr = new ResourceManager;
	}
	return myResource_ptr;
}
