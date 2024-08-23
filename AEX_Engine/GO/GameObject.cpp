#include "GameObject.h"
#include "BaseComponent.h"
#include "GameObjectManager.h"

GameObject::GameObject(std::string str)
{
	GameObjectManager::GetGOMPtr()->counter++;
	GameObjectManager::GetGOMPtr()->InsertObj(this, str);
}

GameObject::GameObject(const GameObject& other)
{
	//deep copy
	for (auto& iter : other.components) {
		components.insert({ iter.first, iter.second });
	}
}

const GameObject& GameObject::operator=(const GameObject& other)
{
	for (auto& iter : other.components) {
		components.insert({ iter.first, iter.second });
	}
	return (*this);
}

GameObject::~GameObject()
{
	GameObjectManager::GetGOMPtr()->RemoveObj(this);
	GameObjectManager::GetGOMPtr()->counter--;
	clear();
}

std::map<std::string, BaseComponent*>& GameObject::GetComponents()
{
	return components;
}

void GameObject::clear()
{
	for (auto iter : components)
	{
		delete iter.second;
	}
}