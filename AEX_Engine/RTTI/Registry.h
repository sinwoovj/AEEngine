#pragma once
#include <map>
#include <string>
#include "BaseRTTI.h"

class Registry
{
	//Singleton
	static Registry* ptr;
	Registry(); //Default constructor
	~Registry(); //Destructor

	Registry(const Registry&) = delete;
	const Registry& operator=(const Registry&) = delete;


	//map with names/funtion_pointers
	std::map<std::string, BaseRTTI* (*)(void)> rttiMap;

public:

	//Single interface
	static Registry* GetPtr();
	static void Delete();

	//Some interface to find inside me
	//TODO: 
	BaseRTTI* FindAndCreate(const std::string& type);
};