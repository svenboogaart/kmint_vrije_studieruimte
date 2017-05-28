#pragma once
#include "PlayerBase.h"
class GoalKeeper:PlayerBase
{
public:
	GoalKeeper(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate);
};

