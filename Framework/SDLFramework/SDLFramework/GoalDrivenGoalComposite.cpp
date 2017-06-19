#include "GoalDrivenGoalComposite.h"



GoalDrivenGoalComposite::GoalDrivenGoalComposite()
{
}


GoalDrivenGoalComposite::~GoalDrivenGoalComposite()
{
}

void GoalDrivenGoalComposite::AddSubGoal(std::shared_ptr<GoalDrivenGoal> goal)
{
	m_goals.push_back(goal);
}

GOALSTATUS GoalDrivenGoalComposite::Process(double deltaTime)
{
	if (m_goals.back()->isCompleted())
	{

		m_goals.pop_back();
		if (m_goals.size() > 0) {
			m_goals.back()->Activiate(m_entity);
		}

	}
	if (m_goals.size() > 0)
	{
		if (!m_goals.back()->isStarted())
		{
			m_goals.back()->Activiate(m_entity);
		}
		m_goals.back()->Process(deltaTime);		
	}
	else
	{
		InitSubGoals();
	}
	return GOALSTATUS::ACTIVE;
}

void GoalDrivenGoalComposite::clearSubGoals()
{
	m_goals.clear();
}

