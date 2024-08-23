#pragma once
#include "AEVec2.h"
#include "LogicComponent.h"

class BallComp : public LogicComponent
{
	AEVec2 direction;
	float moveSpeed;
	float acceleration;
	float leftLimit;
	float rightLimit;
	float topLimit;
	float bottomLimit;

	// public 
	//playercomp << productor
public:
	BallComp(GameObject* owner);
	~BallComp();
	//update
	void Reset();
	void BallReset(bool state);
	void Update() override;
	void LoadFromJson(const json& data) override {};
	json SaveToJson() override { return json{}; };
};