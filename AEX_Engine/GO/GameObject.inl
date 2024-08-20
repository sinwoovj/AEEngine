#include <typeinfo>
#include <string>
#include "GameObject.h"

template<typename T>
inline void GameObject::AddComponent()
{
	components.insert({ typeid(T).name(), new T(this)});
}

template<typename T>
inline void GameObject::AddComponent(T* component)
{
	components.insert({ typeid(T).name(), component });
}

template<typename T>
inline T* GameObject::GetComponent()
{
	std::string name = typeid(T).name();
	if (ExistComponent(name))
	{
		return dynamic_cast<T*>(components.find(name)->second);
	}
	return nullptr;
}

template<typename T>
inline void GameObject::RemoveComponent(T* component)
{
	T* p = GetComponent<T>(component);

	if (p)
	{
		delete p;
		components.erase(typeid(T).name());
	}
}

template<typename T>
inline T* GameObject::FindComponent()
{
	if (components.find(typeid(T).name()) != components.end())
		return  static_cast<T*>(components.find(typeid(T).name())->second);
	return nullptr;
}
