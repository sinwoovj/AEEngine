#include "BallComp.h"
#include "AEEngine.h"
#include "AEInput.h"
#include "TransformComp.h"
#include "RigidBody.h"
#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include "Calculate.h"
BallComp::BallComp(GameObject* owner) : LogicComponent(owner)
{
	direction = { 0, 0 };
	moveSpeed = 100;
	topLimit = 375;
	bottomLimit = -375;
	ComponentManager<BallComp>::GetManager()->AddComponent(this);
}
BallComp::~BallComp()
{

	ComponentManager<BallComp>::GetManager()->RemoveComponent(this);
}

void normalizationVec2(AEVec2& vector)
{
	if (vector.x >= vector.y)
	{
		vector.x = 1;
		vector.y = vector.y / vector.x;
	}
	else
	{
		vector.x = vector.x / vector.y;
		vector.y = 1;
	}
}

void BallComp::Reset()
{
	srand(static_cast<unsigned int>(time(0)));
	TransformComp* t = own->FindComponent<TransformComp>();
	RigidBody* r = own->FindComponent<RigidBody>();
	r->ClearVelocity();
	t->SetPos({ 0, 0 });
	float x = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;  // -1 ~ 1 사이의 임의의 실수 생성
	float y = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;  // -1 ~ 1 사이의 임의의 실수 생성
	direction = { x, y };
	r->AddVelocity(direction.x * moveSpeed, direction.y * moveSpeed);
}
void BallComp::Update()
{
	TransformComp* t = own->FindComponent<TransformComp>();
	RigidBody* r = own->FindComponent<RigidBody>();

	//if (t->GetPos().y > topLimit ||
	//	t->GetPos().y < bottomLimit ||
	//	RangeTest(t->GetPos(), 30, Circle, , 0, Rect, { 20, 150 }) || //위치, 사이즈(지름), 모양, 위치, 사이즈, 모양, 사이즈(벡터)
	//	RangeTest(t->GetPos(), 30, Circle, , 0, Rect, { 20, 150 }))
	//{
	//	
	//}
}