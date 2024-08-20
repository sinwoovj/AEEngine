#pragma once

#include "ComponentManager.h"
#include "EngineComponent.h"
#include "AEMath.h"

class TransformComp : public EngineComponent
{
	AEVec2 pos;
	AEVec2 scale;
	float rot;

	AEMtx33 transformMatrix;

	void CalculateMatrix();

public:
	TransformComp(GameObject* obgj);
	
	void LoadFromJson(const json& data) override;
	json SaveToJson() override;

	void Update() override;

	//Gettors
	const AEVec2& GetPos() const { return pos; };
	const AEVec2& GetScale() const { return scale; };
	const float& GetRot() const { return rot; };
	const AEMtx33& GetMatrix() const { return transformMatrix; };


	//Mutators
	void SetPos(const AEVec2& otherPose);
	void SetScale(const AEVec2& otherScale);
	void SetRot(const float& otherRot);

	//Other Fn
	void PtrintMatrix();

	//For the RTTI
	static BaseRTTI* CreateTransformComp();
	static constexpr const char* TransformTypeName = "TransformComp";
};