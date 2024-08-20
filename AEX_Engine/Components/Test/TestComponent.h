#pragma once
#include "BaseComponent.h"
#include <string>


class TestComponent : public BaseComponent
{
public:
	TestComponent(GameObject* owner);
	~TestComponent();
};