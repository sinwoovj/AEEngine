#pragma once
#include <vector>
#include <string>
#include <typeinfo>

template <typename T>
class ComponentManager
{
	std::vector<T*> components;
	//Copy constructor
	ComponentManager(const ComponentManager& other) = delete;
	//Asignment operator
	const ComponentManager& operator=(const ComponentManager& other) = delete;
	
protected:

	~ComponentManager() = default;
	ComponentManager() = default;
public:
	static ComponentManager* my_manager_ptr;
	void AddComponent(T* component);
	void RemoveComponent(T* component);
	static ComponentManager* GetManager();
	static void clear();
	void Update();

};

#include "ComponentManager.inl"