#include "PlayerBase.h"
#include "MovingEntityStates.h"
#include "SoccerTeam.h"
#include "RandomGenerator.h"

SoccerTeam * PlayerBase::getTeam()
{
	return m_team;
}

PlayerBase::PlayerBase(Vector2D initialPosition, SoccerPitch* pitch, SoccerTeam * team)
	:MovingEntity(initialPosition.getX(), initialPosition.getY(), 50, 50, 0.7, 90, 25, 2000,pitch)
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

Vector2D PlayerBase::getReceivePosition()
{
	return m_receivePosition;
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
	return (m_kicked <= 0);
}

void PlayerBase::kicked()
{
	m_kicked = 0.3;
}

void PlayerBase::setAttackingPosition()
{
	int max = 0;
	int min = 5;
	int randX = rand()%(max-min + 1) + min;
	int randY = rand() % (max - min + 1) + min;
	if (m_team->getColor() == TEAMCOLOR::BLUE)
	{

	m_targetPosition = m_attackPosition + Vector2D(randX, randY);
	}
	else
	{
		m_targetPosition = m_attackPosition - Vector2D(randX, randY);
	}
	//m_targetPosition = m_attackPosition;
}

void PlayerBase::Update(double deltaTime)
{
	if (m_kicked > 0)
	{
		m_kicked -= deltaTime;
	}
	m_stateMachine->update(deltaTime);
}

void PlayerBase::setDefendingPosition()
{
	int max = 50;
	int min = 5;
	int randX = rand() % (max - min + 1) + min;
	int randY = rand() % (max - min + 1) + min;
	if (m_team->getColor() == TEAMCOLOR::BLUE)
	{

		m_targetPosition = m_startPosition + Vector2D(randX, randY);
	}
	else
	{
		m_targetPosition = m_startPosition - Vector2D(randX, randY);
	}
}

void PlayerBase::ReceiveBall(Vector2D position)
{
	m_receivePosition = position;
	m_team->SetReceivingPlayer(this);
	m_team->SetControllingPlayer(this);
	SetState(std::make_shared<ReceiveState>());
}


double PlayerBase::distanceToGoal()
{
	if (isRedTeam())
	{
		return(m_position.distanceTo(Vector2D(0, 300)));
	}
	else
	{
		return (m_position.distanceTo(Vector2D(1000, 300)));
	}
}

bool PlayerBase::isRedTeam()
{
	return (getTeam()->getColor() == TEAMCOLOR::RED);
}
