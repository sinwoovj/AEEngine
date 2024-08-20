#include "GameStateManager.hpp"
#include "BaseLevel.hpp"
#include "ComponentManager.h"
#include "TestComponent.h"
#include "EngineComponent.h"
#include "LogicComponent.h"
#include "SpriteComponent.h"
#include "AudioComponent.h"
#include "Rigidbody.h"
#include "Resource.h"
#include "PlayerComp.h"
#include "PlayerComp2.h"

GSM::GameStateManager* GSM::GameStateManager::ptr = nullptr;

GSM::GameStateManager::GameStateManager() : previousLevel(nullptr), currentLevel(nullptr)
{
}

GSM::GameStateManager::~GameStateManager()
{
    if (previousLevel)
        delete previousLevel;
    if (currentLevel)
        delete currentLevel;
}

GSM::GameStateManager* GSM::GameStateManager::GetGSMPtr()
{
    if (ptr == nullptr)
    {
        ptr = new GameStateManager;
    }

    return ptr;
}

void GSM::GameStateManager::DeleteGSM()
{
    if (ptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

void GSM::GameStateManager::Init()
{
    if (currentLevel)
    {

        currentLevel->Init();
    }
}

void GSM::GameStateManager::Update()
{
    if (currentLevel)
    {
        ComponentManager<TestComponent>::GetManager()->Update();
        ComponentManager<AudioComponent>::GetManager()->Update();
        ComponentManager<SpriteComponent>::GetManager()->Update();
        ComponentManager<PlayerComp>::GetManager()->Update();
        ComponentManager<PlayerComp2>::GetManager()->Update();
        ComponentManager<RigidBody>::GetManager()->Update();
        currentLevel->Update();
    }
}

void GSM::GameStateManager::Exit()
{
    if (currentLevel)
    {
        ComponentManager<TestComponent>::clear();

        currentLevel->Exit();

    }
}

void GSM::GameStateManager::ChangeLevel(BaseLevel* newLvl)
{
    if (previousLevel)
        delete previousLevel;

    previousLevel = currentLevel;

    //Exit the current level
    Exit();

    //Current level is now the "next" level
    currentLevel = newLvl;

    //Initialize the level
    Init();
}

bool GSM::GameStateManager::ShouldExit()
{
    return currentLevel == nullptr;
}
