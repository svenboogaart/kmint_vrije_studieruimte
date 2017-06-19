#include "DropOil.h"
#include "GoalMoveToDropPosition.h";
#include "GoalReturnToCorner.h";
#include "GoalDropOil.h";


DropOil::DropOil(MovingEntity * entity)
{
	m_entity = entity;
	InitSubGoals();
	m_started = true;
}


DropOil::~DropOil()
{
}

void DropOil::Activiate(MovingEntity* entity)
{
	m_entity = entity;
	m_started = true;
	clearSubGoals();
	InitSubGoals();
}

void DropOil::Terminate()
{
}

bool DropOil::isCompleted()
{
	return false;
}

void DropOil::InitSubGoals()
{
	AddSubGoal(std::make_shared<GoalReturnToCorner>());
	AddSubGoal(std::make_shared<GoalDropOil>());
	AddSubGoal(std::make_shared<GoalMoveToDropPosition>());
	
}
