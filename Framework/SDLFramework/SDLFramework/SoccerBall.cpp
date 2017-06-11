#include "SoccerBall.h"
#include "MovingEntityStates.h"
#include <math.h> 


SoccerBall::SoccerBall(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, SoccerPitch* pitch)
	:MovingEntity(x, y, width, height, mass, maxSpeed, maxForce, maxTurnRate, pitch)
{
	m_texture = FWApplication::GetInstance()->LoadTexture("football.png");
	m_stateMachine = std::make_shared<StateMachine<MovingEntity>>(this);
	std::shared_ptr<TestState> initialState = std::make_shared<TestState>();
	m_stateMachine->setCurrentState(initialState);
	m_stateMachine->changeState(initialState);
	m_type = EntityType::BALL;
}


void SoccerBall::Kick(Vector2D direction, double force)
{
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
