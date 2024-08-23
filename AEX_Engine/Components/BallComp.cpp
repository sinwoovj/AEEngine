#include "BallComp.h"
#include "AEEngine.h"
#include "AEVec2.h"
#include "AEInput.h"
#include "TransformComp.h"
#include "RigidBody.h"
#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include "Calculate.h"
#include "GameObjectManager.h"
#include "MainMenu.hpp"
#include "AEEngine.h"
BallComp::BallComp(GameObject* owner) : LogicComponent(owner)
{
	direction = { 0, 0 };
	moveSpeed = 500;
	leftLimit = -780;
	rightLimit = 780;
	topLimit = 430;
	bottomLimit = -430;
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

void BallComp::BallReset(bool state) // true = 양수, false = 음수
{
	srand(static_cast<unsigned int>(time(0)));
	TransformComp* t = own->FindComponent<TransformComp>();
	RigidBody* r = own->FindComponent<RigidBody>();
	r->ClearVelocity();
	t->SetPos({ 0, 0 });
	moveSpeed = 500;
	acceleration = 1.1f;
	float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0 - 1.0;  // -1 ~ 1 사이의 임의의 실수 생성
	float y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0 - 1.0;  // -1 ~ 1 사이의 임의의 실수 생성
	//x = 1; y = 0;
	if (state)
	{
		x = (x < 0) ? -x : x;
	}
	else
	{
		x = (x > 0) ? -x : x;
	}
	direction = { x, y };
	r->AddVelocity(direction.x * moveSpeed, direction.y * moveSpeed);
}

void BallComp::Reset()
{
	Levels::MainLevel::isEnd = 0;
	Levels::MainLevel::isScore = 0;
	Levels::MainLevel::player1score = 0;
	Levels::MainLevel::player2score = 0;

	BallReset(rand() % 2);
}


AEVec2 reflect(AEVec2& v, AEVec2& normal) {
	AEVec2 projection;
	AEVec2Project(&projection, &v, &normal);
	AEVec2Scale(&projection, &projection, -1);
	AEVec2Scale(&projection, &projection, 2);
	AEVec2Add(&projection, &projection, &v);
	return projection;
}

void BallComp::Update()
{
	if (AEInputCheckCurr(AEVK_R))
	{
		Reset();
	}
	TransformComp* t = own->FindComponent<TransformComp>();
	RigidBody* r = own->FindComponent<RigidBody>();
	AEVec2 normal;   // 수직 벽의 법선 벡터
	AEVec2 V = r->GetVelocity();
	if (t->GetPos().x < leftLimit) // player 2 win
	{
		std::cout << "player2 scored!" << std::endl;
		Levels::MainLevel::isScore = 2;
		Levels::MainLevel::player2score++;
		if (Levels::MainLevel::player2score >= MAXSCORE)
		{
			std::cout << "player2 win!" << std::endl;
			Levels::MainLevel::isEnd = 2;
		}
		else {
			Levels::MainLevel::scoreTrigger = true;
			BallReset(true);
		}
	}
	else if (t->GetPos().x > rightLimit) // player 1 win
	{
		std::cout << "player1 scored!" << std::endl;
		Levels::MainLevel::isScore = 1;
		Levels::MainLevel::player1score++;
		if (Levels::MainLevel::player1score >= MAXSCORE)
		{
			std::cout << "player1 win!" << std::endl;
			Levels::MainLevel::isEnd = 1;
		}
		{
			Levels::MainLevel::scoreTrigger = true;
			BallReset(false);
		}
	}
	else if (t->GetPos().y > topLimit)
	{
		normal = { 0.0f, -1.0f };
		direction = reflect(V, normal);
		r->SetVelocity({ direction.x * acceleration, direction.y * acceleration });
		//std::cout << "crush!" << std::endl;

	}
	else if (t->GetPos().y < bottomLimit)
	{
		normal = { 0.0f, 1.0f };
		direction = reflect(V, normal);
		r->SetVelocity({ direction.x * acceleration, direction.y * acceleration });
		//std::cout << "crush!" << std::endl;

	}
	else if (
		RangeTest(
		t->
		GetPos(), 30, Square,
		GameObjectManager::GetGOMPtr()->
		GetObj("player1")->
		FindComponent<TransformComp>()->
		GetPos(), 0, Rect, { 20, 150 }))
		//위치, 사이즈(지름), 모양, 위치, 사이즈, 모양, 사이즈(벡터)
	{
		normal = { 1.0f, 0.0f };
		direction = reflect(V, normal);
		r->SetVelocity({ direction.x * acceleration, direction.y * acceleration });
		//std::cout << "crush!" << std::endl;

	}
	else if (
		RangeTest(
		t->
		GetPos(), 30, Square, 
		GameObjectManager::GetGOMPtr()->
		GetObj("player2")->
		FindComponent<TransformComp>()->
		GetPos(), 0, Rect, { 20, 150 }))
	{
		normal = { -1.0f, 0.0f };
		direction = reflect(V, normal);
		r->SetVelocity({ direction.x * acceleration, direction.y * acceleration });
		//std::cout << "crush!" << std::endl;
	}
}