#include "PlayerBase.h"
#include "MovingEntityStates.h"
#include "SoccerTeam.h"


SoccerTeam * PlayerBase::getTeam()
{
	return m_team;
}

PlayerBase::PlayerBase(Vector2D initialPosition, SoccerPitch* pitch, SoccerTeam * team)
	:MovingEntity(initialPosition.getX(), initialPosition.getY(), 50, 50, 0.7, 70, 20, 2000,pitch)
{
	m_team = team;
	m_stateMachine = std::make_shared<StateMachine<PlayerBase>>(this);
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

std::shared_ptr<StateMachine<PlayerBase>> PlayerBase::getStateMachine()
{
	return m_stateMachine;
}

void PlayerBase::SetState(std::shared_ptr<State<PlayerBase>> state)
{
	m_stateMachine->setCurrentState(state);
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

void PlayerBase::setAttackingPosition()
{
	m_targetPosition = m_attackPosition;
}

void PlayerBase::Update(double deltaTime)
{
	m_stateMachine->update(deltaTime);
}

void PlayerBase::setDefendingPosition()
{
	m_targetPosition = m_startPosition;
}

