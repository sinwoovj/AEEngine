#pragma once
#include "BaseRTTI.h"

/*
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
*/
class GameObject;

class BaseComponent : public BaseRTTI
{
    BaseComponent() = default;
public:
    BaseComponent(GameObject* owner) : own(owner) {}
    virtual ~BaseComponent() = default;
    virtual void Update() = 0;

    virtual json SaveToJson() = 0;
    virtual void LoadFromJson(const json&) = 0;
protected:
    GameObject* own;
};