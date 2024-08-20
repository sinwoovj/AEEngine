#include "TransformComp.h"
#include <iostream>
void TransformComp::CalculateMatrix()
{
	//Create a translate
	AEMtx33 translateMtx;
	AEMtx33Trans(&translateMtx, pos.x, pos.y);

	//Create a Rotatioin matrix
	AEMtx33 rotationMtx;
	AEMtx33Rot(&rotationMtx, rot);

	//Create a scale matrix
	AEMtx33 scaleMtx;
	AEMtx33Scale(&scaleMtx, scale.x, scale.y);

	//Concatenate them
	AEMtx33Concat(&transformMatrix, &rotationMtx, &scaleMtx);
	AEMtx33Concat(&transformMatrix, &translateMtx, &transformMatrix);
}

TransformComp::TransformComp(GameObject* obgj) : EngineComponent(obgj), pos(), scale(), rot(0), transformMatrix()
{
	pos.x = 0;
	pos.y = 0;

	scale.x = 1;
	scale.y = 1;

	CalculateMatrix();
}

void TransformComp::LoadFromJson(const json& data)
{
	//Check how you saved, load from there

	auto compData = data.find("CompData");

	if (compData != data.end())
	{
		auto p = compData->find("Pos");
		
		pos.x = p->begin().value();
		pos.y = (p->begin() + 1).value();
		auto s = compData->find("Sca");
		
		scale.x = s->begin().value();
		scale.y = (s->begin() + 1).value();

		auto r = compData->find("Rot");
		
		rot = r.value();
	}

	//Data is loaded

	//Utilize the data
	CalculateMatrix();

}

json TransformComp::SaveToJson()
{
	json data;
	//Save the type
	data["Type"] = TransformTypeName;
	//Save my data
	json compData;
		//pos
		compData["Pos"] = { pos.x, pos.y };
		//sca
		compData["Sca"] = { scale.x, scale.y };
		//rot
		compData["Rot"] = rot;

	data["CompData"] = compData;
	
	return data;
}

void TransformComp::Update()
{
	CalculateMatrix();
}

void TransformComp::SetPos(const AEVec2& otherPose)
{
	this->pos = otherPose;

	CalculateMatrix();
}

void TransformComp::SetScale(const AEVec2& otherScale)
{
	this->scale = otherScale;

	CalculateMatrix();
}

void TransformComp::SetRot(const float& otherRot)
{
	this->rot = otherRot;

	CalculateMatrix();
}

void TransformComp::PtrintMatrix()
{
		std::cout << "Printing Transform Comp. With this values" << std::endl;
		std::cout << "Translate : " << pos.x << " " << pos.y << std::endl;
		std::cout << "Rotation : " << rot << std::endl;
		std::cout << "Scale : " << scale.x << " " << scale.y << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|";
		for (int x = 0; x < 3; x++)
		{
			std::cout << " " << transformMatrix.m[i][x];
		}
		std::cout << "|";
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
	}
}
#include "GameObject.h"
#include "GameObjectManager.h"


BaseRTTI* TransformComp::CreateTransformComp()
{ 
	BaseRTTI* p = new TransformComp(GameObjectManager::GetGOMPtr()->GetLastObj());
	return p;
}

