#pragma once

#include "LogicComponent.h"

class PlayerComp : public LogicComponent
{
	float moveSpeed;
	float rotateSpeed;

	float topLimit;
	float bottomLimit;
	// public 
	//playercomp << productor
public:
	PlayerComp(GameObject* owner);
	~PlayerComp();
	//update
	void Update() override;

	void LoadFromJson(const json& data) override {};
	json SaveToJson() override { return json{}; };
};