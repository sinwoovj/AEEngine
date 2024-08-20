#pragma once
#include "BaseComponent.h"

class EngineComponent : public BaseComponent
{
public:
	EngineComponent(GameObject* owner);
	~EngineComponent();

	virtual json SaveToJson() = 0;
	virtual void LoadFromJson(const json&) = 0;
};