#pragma once
#include "TestComponent.h"

class TestFunc : public TestComponent
{
	TestFunc() = default;
public:
	TestFunc(GameObject* owner) : TestComponent(owner) {};
	void Update() override;
	bool RandomExcute(int& index, int& randomInt);
	void Print(std::string context);
};