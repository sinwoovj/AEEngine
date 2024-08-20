#pragma once

#include "BaseLevel.hpp"

namespace Levels
{
	class GoalLevel : public GSM::BaseLevel
	{
		void Init() override;
		void Update() override;
		void Exit() override;
	};
}