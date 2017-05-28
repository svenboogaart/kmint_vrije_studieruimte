#pragma once
#include "Vector2D.h"
#include "MovingEntity.h"
class SoccerBall:public MovingEntity
{
public:
	SoccerBall(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate);
	void Kick(Vector2D direction, double force);
	void Trap();
	double TimeToCoverDistance(Vector2D from, Vector2D to, double force);

};

