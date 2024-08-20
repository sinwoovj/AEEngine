#pragma once
#include <unordered_map>
#include <string>
#include "TextureResourceComp.h"
#include "AudioResourceComp.h"
#include "Resource.h"

enum fileExt { png, mp3, wav, jpg, None };

class ResourceManager
{
	//Singleton

private:
	ResourceManager() = default;

	//Remove the compiler defined Copy Constructor and Asignment operator
	ResourceManager(const ResourceManager& other) = delete;
	const ResourceManager& operator= (const ResourceManager& other) = delete;
public:
	static ResourceManager* myResource_ptr;
	std::map<std::string, Resource*> files;
	//map to hold names / resource*
	static std::unordered_map<std::string, fileExt> const fileExtmap;
	//Get<T> fn that returns a T* to the data allocated in the resource with that name
		//IF the resource does not exist, load it
		//Load a resource depends on the EXTENSION of the file
			//switch statement, creating an approapiate constructor for the extension
	template <typename T>
	T* Get(std::string filepath);
	//Unload(name fn that removes 1 from the counter of the resource.
		//IF the counter is 0, unload the resource, delete it, and remove from map
	void Unload(std::string filepath);
	//Fn to unload All Resources
	void Unload();

	static ResourceManager* GetResourceManager();
};

template<typename T>
inline T* ResourceManager::Get(std::string filepath)
{
	std::string filename = filepath.substr(filepath.find_last_of("/") + 1);
	std::string ext = filename.substr(filename.find_last_of(".") + 1);

	fileExt extension;
	auto it = fileExtmap.find(ext);
	if (it != fileExtmap.end()) {
		extension = it->second;
	}
	else { extension = None; }
	
	Resource* p = nullptr;
	if (files.find(filepath) == files.end())
	{
		switch (extension)
		{
		case png:

		case jpg:
			p = new TextureResourceComp;
			p->Load(filepath);
			files.insert({ filepath, p });
			return dynamic_cast<T*>(p);
		case mp3:

		case wav:
			p = new AudioResourceComp;
			p->Load(filepath);
			files.insert({ filepath, p });
			return dynamic_cast<T*>(p);
		default:
			return nullptr;
			break;
		}
	}
	else
	{
		return dynamic_cast<T*>(files.find(filepath)->second);
	}
}