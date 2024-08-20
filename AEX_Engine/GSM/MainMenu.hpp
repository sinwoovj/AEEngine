#pragma once
#include "BaseLevel.hpp"
#include "GameObject.h"

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

		void Init() override;
		void Update() override;
		void Exit() override;
	};
}