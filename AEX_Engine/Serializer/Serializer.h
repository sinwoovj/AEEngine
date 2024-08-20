#pragma once

#include <string>
class Serializer
{
	Serializer() = default;
	//Copy constructor
	Serializer(const Serializer& other) = delete;
	//Asignment operator
	const Serializer& operator=(const Serializer& other) = delete;
public:
	static Serializer* my_serializer_ptr;

	static Serializer* get_serializer_ptr();

	void SaveLevel(const std::string& filename);
	void LoadLevel(const std::string& filename);
	static void clear();
};