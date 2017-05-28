#pragma once
#include "MovingEntity.h"

class PlayerBase :MovingEntity
{
public:
	PlayerBase(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate);
	bool CanPassForward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool CanPassBackward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool WithingShootingRange();
	bool AtTarget();
};

