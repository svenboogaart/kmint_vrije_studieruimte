#pragma once
#include "GoalDrivenGoalComposite.h"
class DropOil :
	public GoalDrivenGoalComposite
{
public:
	DropOil(MovingEntity * entity);
	~DropOil();
	

	// Inherited via GoalDrivenGoalComposite
	virtual void Activiate(MovingEntity*) override;

	virtual void Terminate() override;

	virtual bool isCompleted() override;

	virtual void InitSubGoals() override;

};

