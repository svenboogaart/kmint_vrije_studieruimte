#include "GoalReturnToCorner.h"



GoalReturnToCorner::GoalReturnToCorner()
{
}


GoalReturnToCorner::~GoalReturnToCorner()
{
	
}

void GoalReturnToCorner::Activiate(MovingEntity* entity)
{
	m_entity = entity;
	Vector2D position = m_entity->getPosition();
	double distance1, distance2, distance3, distance4;
	distance1 = position.distanceTo(Vector2D(0, 0));
	distance2 = position.distanceTo(Vector2D(1000, 0));
	distance3 = position.distanceTo(Vector2D(0, 600));
	distance4 = position.distanceTo(Vector2D(1000, 600));
	if (distance1 < distance2 && distance1 < distance3 && distance3 < distance4)
	{
		m_entity->setTargetPosition(Vector2D(0, 0));
	}
	else if (distance2 < distance1 && distance2 < distance3 && distance2 < distance4)
	{
		m_entity->setTargetPosition(Vector2D(1000, 0));
	}
	else if (distance3 < distance1 && distance3 < distance2 && distance3 < distance4)
	{
		m_entity->setTargetPosition(Vector2D(0, 600));
	}
	else
	{
		m_entity->setTargetPosition(Vector2D(1000, 600));
	}
	m_started = true;
}

GOALSTATUS GoalReturnToCorner::Process(double deltaTime)
{
	Vector2D target = m_entity->getTargetPosition();
	m_entity->move(m_entity->getSteeringBehaviour()->arrive(target), deltaTime);
	if (isCompleted())
	{
		return GOALSTATUS::COMPLETED;
	}
	return GOALSTATUS::ACTIVE;
}

void GoalReturnToCorner::Terminate()
{
}

bool GoalReturnToCorner::isCompleted()
{
	if (!m_started)
	{
		return false;
	}
	return m_entity->getPosition().distanceTo(m_entity->getTargetPosition()) < 5;
}
