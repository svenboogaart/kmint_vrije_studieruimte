#pragma once
#include "GoalDrivenGoal.h"
class GoalReturnToCorner :
	public GoalDrivenGoal
{
public:
	GoalReturnToCorner();
	~GoalReturnToCorner();

	// Inherited via GoalDrivenGoal
	virtual void Activiate(MovingEntity*) override;
	virtual GOALSTATUS Process(double deltaTime) override;
	virtual void Terminate() override;
	virtual bool isCompleted() override;
};

