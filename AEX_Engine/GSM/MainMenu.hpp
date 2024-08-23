#pragma once
#include "BaseLevel.hpp"
#include "GameObject.h"
#define MAXSCORE 11

class GameObject;


namespace Levels
{
	class MainLevel : public GSM::BaseLevel
	{
		// none collider &ontrigger
		GameObject* background;

		// collider & ontrigger
		GameObject* points;
		GameObject* finishLine1; 
		GameObject* finishLine2; 
		GameObject* player1;
		GameObject* player2;
		GameObject* ball;
		int counter;

		// functions
		void Init() override;
		void Update() override;
		void Exit() override;

	public:
		// variables
		static float player1score;
		static float player2score;
		static int isScore;
		static int isEnd;
		static bool scoreTrigger;
	};
}