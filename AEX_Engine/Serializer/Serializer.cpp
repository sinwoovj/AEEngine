#include "Serializer.h"
#include <fstream>
#include <iostream>
#include "json.hpp"

//Architecture dependant
#include "GameObjectManager.h"
#include "GameObject.h"
#include "BaseComponent.h"
#include "Registry.h"

//using json = nlohmann::json;			//Map. Orders alphabetically on pushback and insert
using json = nlohmann::ordered_json;	//Map. Keeps the order the variables were declared in

Serializer* Serializer::my_serializer_ptr = nullptr;

Serializer* Serializer::get_serializer_ptr()
{
	if (my_serializer_ptr == nullptr)
	{
		my_serializer_ptr = new Serializer;
	}
	return my_serializer_ptr;
}

void Serializer::LoadLevel(const std::string& filename)
{
	//open file
	std::fstream file;
	file.open(filename, std::fstream::in);

	//Check the file is valid
	if (!file.is_open())
	{
		//print error
		std::cout << filename << " is CAN'T Open." << std::endl;
		//return
		return;
	}

	json AllData;
	file >> AllData;	//The json has all the file data

	for (auto& item : AllData)	//Depending on how you saved, you look for some values or others
	{
		//Create an Object IF this is an obj
		auto obj = item.find("Object");
		if (obj != item.end())	//It was found
		{
			//Create the go
			GameObject* go = GameObjectManager::GetGOMPtr()->AddObj();

			//Find the component section
			auto cmp = item.find("Components");
			if (cmp == item.end())	//NOT FOUND
				continue;

			//Iterate on the json on cmp for each component, add it
			for (auto& c : *cmp)
			{
				auto t = c.find("Type");
				if (t == c.end())	//NOT FOUND
					continue;

				std::string typeName = t.value();	//convert to string

				//Look in the registry for this  type and create it
				BaseRTTI* p = Registry::GetPtr()->FindAndCreate(typeName);

				if (p != nullptr)
					p->LoadFromJson(c);

				//Add the comp to the GameObject
				
				go->AddComponent(static_cast<BaseComponent*>(p));
			}
		}
	}
}


void Serializer::SaveLevel(const std::string& filename)
{
	json AllData;

	//Cousnter instead of name as I do not have one
	int i = 0;

	//iterate on each go
	for (GameObject* go : GameObjectManager::GetGOMPtr()->AllObj())
	{
		json obj;
		obj["Object"] = i++;

		json components;
		//iterate on each component
		for (auto& c : go->GetComponents())
		{
			BaseComponent* comp = c.second;
			components.push_back(comp->SaveToJson());	//Check in a moment
		}

		obj["components"] = components;

		AllData.push_back(obj);
	}

	//Open file
	std::fstream file;
	file.open(filename, std::fstream::out); //Open as write mode. Create it if it does not exist!

	if (!file.is_open())
	{
		//print error
		//return
	}
	//file << AllData;					//All in 1 line
	file << std::setw(2) << AllData;	//Separates in lines and each section
	file.close();
}


void Serializer::clear()
{
	if (my_serializer_ptr != nullptr)
		delete my_serializer_ptr;
	my_serializer_ptr = nullptr;
}