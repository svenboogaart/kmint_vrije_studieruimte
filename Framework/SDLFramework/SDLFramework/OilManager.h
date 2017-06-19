#pragma once
#include "MovingEntity.h"
#include "GoalDrivenGoal.h"
class OilManager :public MovingEntity
{
private:
	std::shared_ptr<GoalDrivenGoal> m_goal;
public:
	OilManager(SoccerPitch * pitch);
	~OilManager();
	void Update(double DeltaTime);
};

