#pragma once
#include "Vector2D.h"
#include "MovingEntity.h"
#include "PlayerBase.h"
class SoccerBall:public MovingEntity
{
private:
	MovingEntity * m_owner;
public:
	SoccerBall(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, SoccerPitch* pitch);
	void Kick(Vector2D direction, double force);
	void Trap(MovingEntity *);
	double TimeToCoverDistance(Vector2D from, Vector2D to, double force);
	Vector2D FuturePosition(double timne);
	void Update(double deltaTime);

};

