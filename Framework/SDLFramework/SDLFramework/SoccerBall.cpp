#include "SoccerBall.h"
#include "MovingEntityStates.h"
#include <math.h> 


SoccerBall::SoccerBall(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, SoccerPitch* pitch)
	:MovingEntity(x, y, width, height, mass, maxSpeed, maxForce, maxTurnRate, pitch)
{
	m_texture = FWApplication::GetInstance()->LoadTexture("football.png");
	m_type = EntityType::BALL;
	setHeading(Vector2D(-50, 20));
	setVelocity(Vector2D(250, 210));
}


void SoccerBall::Kick(Vector2D direction, double force)
{
	m_velocity = direction;
}

void SoccerBall::Trap(MovingEntity * owner)
{
	m_owner = owner;
	m_velocity = Vector2D(0, 0);
}

double SoccerBall::TimeToCoverDistance(Vector2D from, Vector2D to, double force)
{
	double length = sqrt(from.distanceTo(to));

	return length/force;
}

Vector2D SoccerBall::FuturePosition(double time)
{
	return  m_position + (m_velocity*time);
}

void SoccerBall::Update(double deltaTime)
{
	move(Vector2D(0,0) , deltaTime);
}
