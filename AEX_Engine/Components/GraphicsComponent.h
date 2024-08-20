#pragma once
#include "BaseComponent.h"

class GraphicsComponent : public BaseComponent
{
public:
	GraphicsComponent(GameObject* owner);
	~GraphicsComponent();
	virtual json SaveToJson() = 0;
	virtual void LoadFromJson(const json&) = 0;
};