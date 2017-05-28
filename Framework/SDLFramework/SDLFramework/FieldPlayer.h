#pragma once
#include "BasePlayer.h"

class FieldPlayer:BasePlayer
{
public:
	FieldPlayer(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate);
};

