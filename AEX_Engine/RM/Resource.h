#pragma once
#include <string>
#include <map>

class Resource
{
	//pure abstract class
		//IF you inherit from me, you MUST override some fn


	void* data;
public:
	//Use static cast for this to become Texture*, Audio* ... when needed

	//fn to return the data
	virtual void* GetData() = 0;
	//pure virtual fn to LOAD data
	virtual void Load(std::string filepath) = 0;
	//pure virtual fn to UNLOAD data
	virtual void Unload() = 0;

	virtual ~Resource() { } //Otherwise you would not be deleting the spcialized classess
	int counter;
};