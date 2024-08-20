#include "GraphicsComponent.h"
#include "ComponentManager.h"

GraphicsComponent::GraphicsComponent(GameObject* owner) : BaseComponent(owner)
{
	ComponentManager<GraphicsComponent>::GetManager()->AddComponent(this);
}

GraphicsComponent::~GraphicsComponent()
{
	ComponentManager<GraphicsComponent>::GetManager()->RemoveComponent(this);
}
