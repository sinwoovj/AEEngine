#pragma once
#include "EngineComponent.h"

#include "AEVec2.h"

class RigidBody : public EngineComponent
{
	float drag = 1.1f;

	AEVec2 Velocity;
	AEVec2 MaxVelocity;
	//Acceleration?

	bool CheckEpsilon(float v, float EP = EPSILON);
public:
	RigidBody(GameObject* owner);
	~RigidBody();

	//void AddVelocity(const AEVec2& otherVec);
	void AddVelocity(float x, float y);

	void ClearVelocity();

	void Update() override;

	AEVec2 GetVelocity();

	void LoadFromJson(const json& data) override {};
	json SaveToJson() override { return json{}; };
};