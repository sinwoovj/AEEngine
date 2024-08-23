#include "GameObjectManager.h"


GameObjectManager* GameObjectManager::my_gameObject_ptr = nullptr;

std::map<GameObject*, std::string> GameObjectManager::AllObj()
{
	return my_Obj;
}

GameObject* GameObjectManager::AddObj()
{
	GameObject* p = new GameObject("");
	return p;
}

void GameObjectManager::InsertObj(GameObject* target, std::string str)
{
	my_Obj.insert({ target, str });
}

void GameObjectManager::RemoveObj(GameObject* target)
{
	//std::remove(my_Obj.begin(), my_Obj.end(), target);
	auto it = my_Obj.find(target);
	my_Obj.erase(it, my_Obj.end());
}

void GameObjectManager::ClearObj()
{
	my_Obj.clear();
}

GameObject* GameObjectManager::GetObj(const std::string& id) {
	// my_Obj�� ��� ��Ҹ� ��ȸ�ϸ� ID�� ã��
	for (const auto &pair : my_Obj) {
		if (pair.second == id) {
			return pair.first;
		}
	}
	// ��ġ�ϴ� ID�� ���� ��� nullptr ��ȯ
	return nullptr;
}

GameObject* GameObjectManager::GetLastObj()
{
	if (!my_Obj.empty())
	{
		auto it = my_Obj.end();
		--it;
		auto key = it->first;
		return key;
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
