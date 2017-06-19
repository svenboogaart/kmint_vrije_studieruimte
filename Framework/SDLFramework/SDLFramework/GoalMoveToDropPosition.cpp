#include "GoalMoveToDropPosition.h"

void GoalMoveToDropPosition::Activiate(MovingEntity* entity)
{
	m_started = true;
	int max = 1000;
	int min = 0;
	int randX = rand() % (max - min + 1) + min;
	max = 600;
	int randY = rand() % (max - min + 1) + min;
	entity->setTargetPosition(Vector2D(randX, randY));
	m_entity = entity;
}

GOALSTATUS GoalMoveToDropPosition::Process(double deltaTime)
{
	Vector2D target = m_entity->getTargetPosition();
	m_entity->move(m_entity->getSteeringBehaviour()->arrive(target), deltaTime);
	if (isCompleted())
	{
		return GOALSTATUS::COMPLETED;
	}
	return GOALSTATUS::ACTIVE;
}

void GoalMoveToDropPosition::Terminate()
{
}

bool GoalMoveToDropPosition::isCompleted()
{
	if (!m_started)
	{
		return false;
	}
	Vector2D target = m_entity->getTargetPosition();
	if (m_entity->getPosition().distanceTo(target) < 5)
	{
		return true;
	}
	return false;
}

