#pragma once
#include "GoalDrivenGoal.h"
class GoalDropOil :
	public GoalDrivenGoal
{
private:
	bool m_dropped = false;
public:
	

	// Inherited via GoalDrivenGoal
	virtual void Activiate(MovingEntity*) override;

	virtual GOALSTATUS Process(double deltaTime) override;

	virtual void Terminate() override;

	virtual bool isCompleted() override;

};

