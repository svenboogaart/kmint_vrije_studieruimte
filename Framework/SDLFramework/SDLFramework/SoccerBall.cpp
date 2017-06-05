#include "SoccerBall.h"
#include "MovingEntityStates.h"



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

void SoccerBall::Trap()
{
}

double SoccerBall::TimeToCoverDistance(Vector2D from, Vector2D to, double force)
{
	return 0.0;
}
