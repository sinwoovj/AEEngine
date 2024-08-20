#include "Rigidbody.h"
#include "TransformComp.h"
#include "GameObject.h"
#include "ComponentManager.h"
#include "AEEngine.h"
#include "AEFrameRateController.h"

bool RigidBody::CheckEpsilon(float v, float EP)
{
	if (v < -EP || v > EP)
		return true;
	return false;
}

RigidBody::RigidBody(GameObject* owner) : EngineComponent(owner), Velocity(), MaxVelocity()
{
	Velocity.x = 0;
	Velocity.y = 0;
	MaxVelocity.x = 100;
	MaxVelocity.y = 100;
	ComponentManager<RigidBody>::GetManager()->AddComponent(this);
}

RigidBody::~RigidBody()
{
	ComponentManager<RigidBody>::GetManager()->RemoveComponent(this);
}

void RigidBody::AddVelocity(float x, float y)
{
	Velocity.x += x;
	Velocity.y += y;

	AEClamp(Velocity.x, - MaxVelocity.x, MaxVelocity.x);
	AEClamp(Velocity.y, - MaxVelocity.y, MaxVelocity.y);
}

void RigidBody::ClearVelocity()
{
	Velocity.x = 0;
	Velocity.y = 0;
}

void RigidBody::Update()
{
	TransformComp* t = own->FindComponent<TransformComp>();


	float x = t->GetPos().x + Velocity.x * AEFrameRateControllerGetFrameTime(); // + 1.0f / 2 * acc * time *time
	float y = t->GetPos().y + Velocity.y * AEFrameRateControllerGetFrameTime(); // + 1.0f / 2 * acc * time *time
	
	Velocity.x /= drag;
	Velocity.y /= drag;

	//If im too low, just set to 0
	if (CheckEpsilon(Velocity.x) == false)
		Velocity.x = 0;
	if (CheckEpsilon(Velocity.y) == false)
		Velocity.y = 0;

	t->SetPos({ x,y });
}

AEVec2 RigidBody::GetVelocity()
{
	return Velocity;
}
