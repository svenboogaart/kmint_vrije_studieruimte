#pragma once
#include "MovingEntity.h"
#include "Vector2D.h"
class PlayerBase :public MovingEntity
{
private:
public:
	PlayerBase(Vector2D initialPosition, SoccerPitch* pitch);
	bool CanPassForward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool CanPassBackward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool WithingShootingRange();
	bool AtTarget();
};

