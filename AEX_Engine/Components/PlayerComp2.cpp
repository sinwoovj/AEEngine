#include "PlayerComp2.h"
#include "LogicComponent.h"
#include "AEEngine.h"
#include "AEInput.h"
#include "TransformComp.h"
#include "RigidBody.h"

PlayerComp2::PlayerComp2(GameObject* owner) : LogicComponent(owner)
{
	topLimit = 375;
	bottomLimit = -375;
	ComponentManager<PlayerComp2>::GetManager()->AddComponent(this);
}
PlayerComp2::~PlayerComp2()
{
	
	ComponentManager<PlayerComp2>::GetManager()->RemoveComponent(this);
}
void PlayerComp2::Update()
{
	TransformComp* t = own->FindComponent<TransformComp>();
	RigidBody* r = own->FindComponent<RigidBody>();

	if (t->GetPos().y > topLimit)
	{
		r->ClearVelocity();
		t->SetPos({ t->GetPos().x, topLimit });
	}
	else if (t->GetPos().y < bottomLimit)
	{
		r->ClearVelocity();
		t->SetPos({ t->GetPos().x, bottomLimit });
	}
	else
	{
		s32 x, y;
		AEInputGetCursorPosition(&x, &y);
		if (-y + 440 < topLimit && -y + 440 > bottomLimit)
		{
			t->SetPos({ t->GetPos().x,-(float)y + 440 });
		}
	}
}