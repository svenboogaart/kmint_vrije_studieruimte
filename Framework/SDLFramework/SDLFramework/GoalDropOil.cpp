#include "GoalDropOil.h"
#include "SoccerPitch.h"

void GoalDropOil::Activiate(MovingEntity* entity)
{
	m_started = true;
	m_entity = entity;
}

GOALSTATUS GoalDropOil::Process(double deltaTime)
{
	m_entity->getPitch()->DropOil(m_entity->getPosition());
	m_dropped = true;
	if (isCompleted())
	{
		return GOALSTATUS::COMPLETED;
	}
	return GOALSTATUS::ACTIVE;
}

void GoalDropOil::Terminate()
{
}

bool GoalDropOil::isCompleted()
{
	return m_dropped;
}
