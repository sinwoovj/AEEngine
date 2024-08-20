#pragma once

#include "LogicComponent.h"

class PlayerComp2 : public LogicComponent
{
	float moveSpeed;
	float rotateSpeed;

	float topLimit;
	float bottomLimit;
	// public 
	//playercomp << productor
public:
	PlayerComp2(GameObject* owner);
	~PlayerComp2();
	//update
	void Update() override;

	void LoadFromJson(const json& data) override {};
	json SaveToJson() override { return json{}; };
};