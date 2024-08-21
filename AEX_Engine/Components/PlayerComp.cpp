#include "PlayerComp.h"
#include "LogicComponent.h"
#include "AEEngine.h"
#include "AEInput.h"
#include "TransformComp.h"
#include "RigidBody.h"

PlayerComp::PlayerComp(GameObject* owner) : LogicComponent(owner)
{
	moveSpeed = 50;
	
	topLimit = 375;
	bottomLimit = -375;
	ComponentManager<PlayerComp>::GetManager()->AddComponent(this);
}
PlayerComp::~PlayerComp()
{
	
	ComponentManager<PlayerComp>::GetManager()->RemoveComponent(this);
}
void PlayerComp::Update()
{
	TransformComp* t = own->FindComponent<TransformComp>();
	RigidBody* r = own->FindComponent<RigidBody>();

	if (t->GetPos().y > topLimit && r->GetVelocity().y > 0)
	{
		r->ClearVelocity();
		t->SetPos({ t->GetPos().x, topLimit });
	}
	else if (t->GetPos().y < bottomLimit && r->GetVelocity().y < 0)
	{
		r->ClearVelocity();
		t->SetPos({ t->GetPos().x, bottomLimit });
	}
	else
	{
		if (AEInputCheckCurr(AEVK_W))
		{
			if (AEInputCheckCurr(AEVK_LSHIFT))
				r->AddVelocity(0, moveSpeed * 2);
			else
				r->AddVelocity(0, moveSpeed);
		}
		if (AEInputCheckCurr(AEVK_S))
		{
			if (AEInputCheckCurr(AEVK_LSHIFT))
				r->AddVelocity(0, -moveSpeed * 2);
			else
				r->AddVelocity(0, -moveSpeed);
		}
	}
	/*if (AEInputCheckCurr(AEVK_A))
	{
		r->AddVelocity(-moveSpeed, 0);
	}
	if (AEInputCheckCurr(AEVK_D))
	{
		r->AddVelocity(moveSpeed, 0);
	}
	if (AEInputCheckCurr(AEVK_SPACE)) // rigid & rotate init
	{
		r->ClearVelocity();
		t->SetPos({ 0,0 });
		t->SetRot({ 0 });
	}
	if (AEInputCheckCurr(AEVK_Q))
	{
		t->SetRot({ t->GetRot() + rotateSpeed });
	}
	if (AEInputCheckCurr(AEVK_E))
	{
		t->SetRot({ t->GetRot() - rotateSpeed });
	}*/
}