#include "ComponentManager.h"
#include <vector>
#include <algorithm>
template<typename T>
ComponentManager<T>* ComponentManager<T>::my_manager_ptr = nullptr;

template<typename T>
inline void ComponentManager<T>::AddComponent(T* component)
{
	components.push_back(component);
}

template<typename T>
inline void ComponentManager<T>::RemoveComponent(T* component)
{
	components.erase(remove(components.begin(), components.end(), component), components.end());
}


template<typename T>
inline ComponentManager<T>* ComponentManager<T>::GetManager()
{
	if (my_manager_ptr == nullptr)
	{
		my_manager_ptr = new ComponentManager;
	}
	return my_manager_ptr;
}

template<typename T>
inline void ComponentManager<T>::clear()
{
	delete my_manager_ptr;
	my_manager_ptr = nullptr;
}

template<typename T>
inline void ComponentManager<T>::Update()
{
	for (auto& iter : components)
	{
		if(iter != nullptr)
			iter->Update();
	}
}

