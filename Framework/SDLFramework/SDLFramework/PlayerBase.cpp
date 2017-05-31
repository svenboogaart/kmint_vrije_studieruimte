#include "PlayerBase.h"
#include "BallStates.h"


PlayerBase::PlayerBase(Vector2D initialPosition)
	:MovingEntity(initialPosition.getX(), initialPosition.getY(), 50, 50, 10, 200, 200, 100)
{
	m_stateMachine = std::make_shared<StateMachine<MovingEntity>>(this);
	std::shared_ptr<ReturnState> initialState = std::make_shared<ReturnState>();
	m_stateMachine->setCurrentState(initialState);
}


bool PlayerBase::CanPassForward(PlayerBase * receiver, PlayerBase * target, double power)
{
	return false;
}

bool PlayerBase::CanPassBackward(PlayerBase * receiver, PlayerBase * target, double power)
{
	return false;
}

bool PlayerBase::WithingShootingRange()
{
	return false;
}

bool PlayerBase::AtTarget()
{
	return false;
}
