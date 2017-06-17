#pragma once
#include "Telegram.h"
#include "Vector2d.h"
#include "MovingEntity.h"

class BasePlayer:MovingEntity
{
public:
	BasePlayer(double x, double y, double mass, double maxSpeed, double maxForce, double maxTurnRate);
	
};

