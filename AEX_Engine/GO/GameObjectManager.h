#pragma once
#include "GameObject.h"
#include <vector>
#include <algorithm>
#include <map>

class GameObjectManager
{

private:
	GameObjectManager() = default;

	//Remove the compiler defined Copy Constructor and Asignment operator
	GameObjectManager(const GameObjectManager& other) = delete;
	const GameObjectManager& operator= (const GameObjectManager& other) = delete;
	std::map<GameObject*,std::string> my_Obj;
	static GameObjectManager* my_gameObject_ptr;


public:
	int counter; 

	std::map<GameObject*, std::string> AllObj();
	GameObject* AddObj();
	void InsertObj(GameObject* target, std::string str);
	void RemoveObj(GameObject* target);
	void ClearObj();
	GameObject* GetObj(const std::string& id);
	GameObject* GetLastObj();
	static GameObjectManager* GetGOMPtr();
	static void clear();
	//static GameObjectManager* GetGOMPtr()
	//{
	//		static GameObjectManager my_gameObject_ptr;
	//	return &my_gameObject_ptr;
	//}
};

/*
컴포넌트 기반 아키텍처
개요
컴포넌트는 게임 오브젝트(GO) 대신 로직을 포함하는 클래스가 됩니다. 이들은 유사한 인터페이스를 가지기 위해 계층적 클래스 구조를 가집니다.
GO 클래스
•    컨테이너: BaseComponent*의 컨테이너를 가집니다.
•    BaseComponent: 추상 클래스(인터페이스)로 컴포넌트를 선언합니다.
•    함수:
o    ANY TYPE의 컴포넌트 클래스를 컨테이너에 추가합니다.
o    특정 TYPE의 컴포넌트를 이미 가지고 있는지 확인합니다.
o    특정 TYPE의 컴포넌트를 삭제합니다.
•    메모리 관리: 컴포넌트는 힙에 할당되므로 GO가 파괴될 때 컴포넌트도 함께 파괴되어야 합니다.
BaseComponent 클래스
•    추상 클래스: 인터페이스 제공.
•    Update 함수: 로직을 수행하며 상속된 모든 클래스는 동일한 문법으로 이 함수를 사용합니다.
•    다형성: virtual로 선언해야 합니다.
•    소멸자: virtual 소멸자 필수.
•    소유자: GO* 소유자를 가집니다. 소유자 없이는 존재할 수 없습니다.
복사 의미
•    GO를 복사한다는 것은 무엇을 의미합니까?
•    컴포넌트를 복사한다는 것은 무엇을 의미합니까?
컴포넌트 종류
•    LogicComponent: 게임플레이에 특정.
•    EngineComponents: 엔진에 특정 (물리, 수학 등).
•    GraphicsComponents: 그래픽에 특정 (Draw(), 이미지 처리 등).
Manager 클래스
•    관리: 특정 유형의 컴포넌트를 관리.
•    싱글톤: 특정 유형의 매니저는 한 번에 하나만 존재.
•    업데이트: 특정 유형의 모든 컴포넌트를 업데이트.
o    특정 유형의 컴포넌트가 생성될 때 매니저에 추가.
•    컨테이너: 컴포넌트들을 위한 컨테이너.
업데이트 호출
•    GSM 레벨에서 업데이트 등을 호출합니다.
컴포넌트 예시
•    Transform 컴포넌트: GO의 위치, 회전, 크기를 가집니다.
•    로직 컴포넌트: 시뮬레이션 수행.
o    동작 출력.
o    다른 객체 접근.
o    이동 등.
•    Sprite 컴포넌트: 객체를 그립니다.
•    Audio 컴포넌트: 오디오를 재생합니다.
*/