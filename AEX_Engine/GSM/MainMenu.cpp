#include "MainMenu.hpp"
#include "GameStateManager.hpp"
#include "GoalLevel.hpp"
#include "GameObject.h"
#include "TransformComp.h"
#include "AudioComponent.h"
#include "SpriteComponent.h"
#include "PlayerComp.h"
#include "Rigidbody.h"
#include "ResourceManager.h"
#include "Serializer.h"
#include "GameObjectManager.h"
#include <iostream>
#include <string>
#include "PlayerComp2.h"
#include "BallComp.h"

/*
resource origin
sprites :
https://opengameart.org/content/pong-programmer-art
music/sfx :
https://opengameart.org/content/pong-0
https://opengameart.org/content/pong-sfx
*/

void Levels::MainLevel::Init()
{
	background = new GameObject;
	background->AddComponent<AudioComponent>();
	background->FindComponent<AudioComponent>()->
		SetAudio(ResourceManager::GetResourceManager()->
 			Get<AudioResourceComp>("Extern/Assets/pong.mp3")->data);
	background->FindComponent<AudioComponent>()->volume = 1.f;
	background->AddComponent<SpriteComponent>();
	background->FindComponent<SpriteComponent>()->
		SetTexture(ResourceManager::GetResourceManager()->
		Get<TextureResourceComp>("Extern/Assets/court.png")->data);
	background->AddComponent<TransformComp>();
	background->FindComponent<TransformComp>()->SetScale({ 1600, 900 });

	ball = new GameObject;
	ball->AddComponent<SpriteComponent>();
	ball->FindComponent<SpriteComponent>()->
		SetTexture(ResourceManager::GetResourceManager()->
		Get<TextureResourceComp>("Extern/Assets/ball.png")->data);
	ball->AddComponent<TransformComp>();
	ball->FindComponent<TransformComp>()->SetScale({ 30,30 });
	ball->AddComponent<RigidBody>();
	ball->AddComponent<BallComp>();
	ball->FindComponent<BallComp>()->Reset();
	
	player1 = new GameObject;
	player1->AddComponent<SpriteComponent>();
	player1->FindComponent<SpriteComponent>()->
		SetTexture(ResourceManager::GetResourceManager()->
		Get<TextureResourceComp>("Extern/Assets/paddle-blue.png")->data);
	player1->AddComponent<TransformComp>();
	player1->FindComponent<TransformComp>()->SetScale({ 20,150 });
	player1->FindComponent<TransformComp>()->SetPos({ -750, 0 });
	player1->AddComponent<PlayerComp>();
	player1->AddComponent<RigidBody>();

	player2 = new GameObject;
	player2->AddComponent<SpriteComponent>();
	player2->FindComponent<SpriteComponent>()->
		SetTexture(ResourceManager::GetResourceManager()->
		Get<TextureResourceComp>("Extern/Assets/paddle-blue.png")->data);
	player2->AddComponent<TransformComp>();
	player2->FindComponent<TransformComp>()->SetScale({ 20,150 });
	player2->FindComponent<TransformComp>()->SetPos({ 750,0 });
	player2->AddComponent<PlayerComp2>();
	player2->AddComponent<RigidBody>();

	Serializer* s = Serializer::get_serializer_ptr();

	//s->LoadLevel("Test2.json");

	counter = 0;
}

void Levels::MainLevel::Update()
{
	//std::cout << "Main level Update:" << std::endl;
	
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
}

void Levels::MainLevel::Exit()
{
	Serializer* s = Serializer::get_serializer_ptr();
	s->SaveLevel("Test2.json");
	s->clear();
}
