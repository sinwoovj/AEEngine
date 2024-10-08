#pragma once
#include "BaseComponent.h"
#include "GameObject.h"

class LogicComponent : public BaseComponent
{
public :
	LogicComponent(GameObject* owner);
	~LogicComponent();

	virtual void Update() = 0;
	virtual json SaveToJson() = 0;
	virtual void LoadFromJson(const json&) = 0;
};