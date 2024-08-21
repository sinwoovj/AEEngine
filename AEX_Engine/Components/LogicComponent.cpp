#include "LogicComponent.h"
#include "ComponentManager.h"

LogicComponent::LogicComponent(GameObject* owner) : BaseComponent(owner)
{
	ComponentManager<LogicComponent>::GetManager()->AddComponent(this);
}

LogicComponent::~LogicComponent()
{
	ComponentManager<LogicComponent>::GetManager()->RemoveComponent(this);
}