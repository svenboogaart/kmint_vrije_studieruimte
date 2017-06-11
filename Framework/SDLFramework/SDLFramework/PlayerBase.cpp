#include "PlayerBase.h"
#include "MovingEntityStates.h"
#include "SoccerTeam.h"


SoccerTeam * PlayerBase::getTeam()
{
	return m_team;
}

PlayerBase::PlayerBase(Vector2D initialPosition, SoccerPitch* pitch, SoccerTeam * team)
	:MovingEntity(initialPosition.getX(), initialPosition.getY(), 50, 50, 0.7, 200, 300, 2000,pitch)
{
	m_team = team;
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

bool PlayerBase::IsReadyForKick()
{
	return false;
}
