#include "SoccerBall.h"



SoccerBall::SoccerBall(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate)
	:MovingEntity(x, y, width, height, mass, maxSpeed, maxForce, maxTurnRate)
{
	m_texture = FWApplication::GetInstance()->LoadTexture("football.png");
}


void SoccerBall::Kick(Vector2D direction, double force)
{
}

void SoccerBall::Trap()
{
}

double SoccerBall::TimeToCoverDistance(Vector2D from, Vector2D to, double force)
{
	return 0.0;
}
