#pragma once
#include "GoalDrivenGoal.h"

class GoalDrivenGoalComposite : public GoalDrivenGoal
{
protected:
	std::vector<std::shared_ptr<GoalDrivenGoal>>m_goals;
public:
	GoalDrivenGoalComposite();
	~GoalDrivenGoalComposite();
	void AddSubGoal(std::shared_ptr<GoalDrivenGoal> goal);
	GOALSTATUS Process(double deltaTime) override;
	virtual void InitSubGoals() = 0;
	void clearSubGoals();
};

