#pragma once

#include <map>
#include <string>

/*
 GO 클래스
•    컨테이너: BaseComponent*의 컨테이너를 가집니다.
•    BaseComponent: 추상 클래스(인터페이스)로 컴포넌트를 선언합니다.
•    함수:
o    ANY TYPE의 컴포넌트 클래스를 컨테이너에 추가합니다.
o    특정 TYPE의 컴포넌트를 이미 가지고 있는지 확인합니다.
o    특정 TYPE의 컴포넌트를 삭제합니다.
•    메모리 관리: 컴포넌트는 힙에 할당되므로 GO가 파괴될 때 컴포넌트도 함께 파괴되어야 합니다.
*/ 

class BaseComponent;

class GameObject
{
	//std::vector<std::pair<int&,BaseComponent*>> components;
	std::map<std::string ,BaseComponent*> components;
public:
	//Default constructor
	GameObject(std::string str);
	//Copy constructor
	GameObject(const GameObject& other);
	//Asignment operator
	const GameObject& operator=(const GameObject& other);
	//Destuctor
	~GameObject();


	template <typename T>
	void AddComponent();
	
	template <typename T>
	void AddComponent(T* component);
	
	bool ExistComponent(std::string name) { return components.find(name) != components.end(); }
	std::map<std::string ,BaseComponent*>& GetComponents();
	template <typename T>
	T* GetComponent();
	template <typename T>
	void RemoveComponent(T* component);
	template <typename T>
	T* FindComponent();

	//Memory Management
	void clear();

};

#include "GameObject.inl"
