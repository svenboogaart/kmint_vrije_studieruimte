#pragma once
#include "GoalDrivenGoal.h"

class GoalMoveToDropPosition : public GoalDrivenGoal
{
public:

	// Inherited via GoalDrivenGoal
	virtual void Activiate(MovingEntity*) override;

	virtual GOALSTATUS Process(double deltaTime) override;

	virtual void Terminate() override;

	virtual bool isCompleted() override;

};

