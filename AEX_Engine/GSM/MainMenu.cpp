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
#include "AEUtil.h"
#include <sstream>

/*
resource origin
sprites :
https://opengameart.org/content/pong-programmer-art
music/sfx :
https://opengameart.org/content/pong-0
https://opengameart.org/content/pong-sfx
*/
float Levels::MainLevel::player1score = 0;
float Levels::MainLevel::player2score = 0;
int Levels::MainLevel::isScore = false;
int Levels::MainLevel::isEnd = false;
bool Levels::MainLevel::scoreTrigger = false;

std::stringstream str;
std::stringstream score;

s8 pFont;
f64 start;
void Levels::MainLevel::Init()
{
	pFont = AEGfxCreateFont("Extern/Assets/liberation-mono.ttf", 72);
	background = new GameObject("background");
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

	ball = new GameObject("ball");
	ball->AddComponent<SpriteComponent>();
	ball->FindComponent<SpriteComponent>()->
		SetTexture(ResourceManager::GetResourceManager()->
		Get<TextureResourceComp>("Extern/Assets/ball.png")->data);
	ball->AddComponent<TransformComp>();
	ball->FindComponent<TransformComp>()->SetScale({ 30,30 });
	ball->AddComponent<RigidBody>();
	ball->AddComponent<BallComp>();
	ball->FindComponent<BallComp>()->Reset();
	
	player1 = new GameObject("player1");
	player1->AddComponent<SpriteComponent>();
	player1->FindComponent<SpriteComponent>()->
		SetTexture(ResourceManager::GetResourceManager()->
		Get<TextureResourceComp>("Extern/Assets/paddle-blue.png")->data);
	player1->AddComponent<TransformComp>();
	player1->FindComponent<TransformComp>()->SetScale({ 20,150 });
	player1->FindComponent<TransformComp>()->SetPos({ -750, 0 });
	player1->AddComponent<PlayerComp>();
	player1->AddComponent<RigidBody>();

	player2 = new GameObject("player2");
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
	score.str("");
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	//std::cout << "Main level Update:" << std::endl;
	if (Levels::MainLevel::isEnd)
	{
		switch (Levels::MainLevel::isEnd)
		{
		case 1:
			str << "player 1 is won!!";
			break;
		case 2:
			str << "player 2 is won!!";
			break;
		}
		//s8 fontId, const char* str, f32 x, f32 y, f32 scale, f32 red, f32 green, f32 blue, f32 alpha
		AEGfxPrint(pFont, str.str().c_str(), -0.6, 0.1, 1.2, 1, 1, 1, 1); // score event
	}
	if (Levels::MainLevel::isScore)
	{
		switch (Levels::MainLevel::isScore)
		{
		case 1:
			str << "player 1 is scored!!";
			break;
		case 2:
			str << "player 2 is scored!!";
			break;
		}
		AEGetTime(&start);
	}
	if (Levels::MainLevel::scoreTrigger)
	{
		f64 now;
		AEGetTime(&now);
		f64 duration = now - start;
		if (duration > (double)2) {
			Levels::MainLevel::scoreTrigger = false;
			str.str("");
		}
		else {
			Levels::MainLevel::isScore = 0;
			AEGfxPrint(pFont, str.str().c_str(), -0.6, 0.1, 1.2, 1, 1, 1, 1); // win event
		}
		//std::cout << duration << " , " << str.str().c_str() << std::endl;
	}
	
	
	// score
	score << Levels::MainLevel::player1score << " : " << Levels::MainLevel::player2score;
	AEGfxPrint(pFont, score.str().c_str(),-0.135, 0.8, 1, 1, 1, 1, 1); // score board
}

void Levels::MainLevel::Exit()
{
	AEGfxDestroyFont(pFont);
	Serializer* s = Serializer::get_serializer_ptr();
	s->SaveLevel("Test2.json");
	s->clear();
}
