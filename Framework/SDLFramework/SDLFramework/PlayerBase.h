#pragma once
#include "MovingEntity.h"
#include "Vector2D.h"
class PlayerBase :public MovingEntity
{
public:
	PlayerBase(Vector2D initialPosition);
	bool CanPassForward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool CanPassBackward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool WithingShootingRange();
	bool AtTarget();
};

