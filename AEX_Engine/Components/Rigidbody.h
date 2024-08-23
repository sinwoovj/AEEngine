#pragma once
#include "EngineComponent.h"

#include "AEVec2.h"

class RigidBody : public EngineComponent
{
	//저항 값으로, 1보다 작으면 속도는 점점 증가하고 1보다 크면 속도는 점점 감소한다. 1일 시에는 등속운동을 한다.
	float drag = 1; 

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
	void SetVelocity(AEVec2 vec);

	void LoadFromJson(const json& data) override {};
	json SaveToJson() override { return json{}; };
};