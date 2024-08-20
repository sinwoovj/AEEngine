#include "GameObjectManager.h"


GameObjectManager* GameObjectManager::my_gameObject_ptr = nullptr;

std::vector<GameObject*> GameObjectManager::AllObj()
{
	return my_Obj;
}

GameObject* GameObjectManager::AddObj()
{
	GameObject* p = new GameObject;
	my_Obj.push_back(p);
	return p;
}

void GameObjectManager::InsertObj(GameObject* target)
{
	my_Obj.push_back(target);
}

void GameObjectManager::RemoveObj(GameObject* target)
{
	std::remove(my_Obj.begin(), my_Obj.end(), target);
}

void GameObjectManager::ClearObj()
{
	my_Obj.clear();
}

GameObject* GameObjectManager::GetObj(GameObject* target)
{
	if (find(my_Obj.begin(), my_Obj.end(), target) == my_Obj.end()) { // vector내에 0이 존재하지 않음
		return nullptr;
	}
	return my_Obj.at(find(my_Obj.begin(), my_Obj.end(), target) - my_Obj.begin());
}

GameObject* GameObjectManager::GetLastObj()
{
	if (!my_Obj.empty())
	{
		return my_Obj.back();
	}
	return nullptr;
}

GameObjectManager* GameObjectManager::GetGOMPtr()
{
	if (my_gameObject_ptr == nullptr)
	{
		my_gameObject_ptr = new GameObjectManager;
	}
	return my_gameObject_ptr;
}

void GameObjectManager::clear()
{
	if (my_gameObject_ptr != nullptr)
		delete my_gameObject_ptr;
	my_gameObject_ptr = nullptr;
}
