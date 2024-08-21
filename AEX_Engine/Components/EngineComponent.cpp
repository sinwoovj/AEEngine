#include "EngineComponent.h"

#include "ComponentManager.h"

EngineComponent::EngineComponent(GameObject* owner) : BaseComponent(owner)
{
	ComponentManager<EngineComponent>::GetManager()->AddComponent(this);
}

EngineComponent::~EngineComponent()
{
	ComponentManager<EngineComponent>::GetManager()->RemoveComponent(this);
}