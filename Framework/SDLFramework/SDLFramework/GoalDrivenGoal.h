#pragma once
#include <vector>
#include <memory>
#include "MovingEntity.h"

enum GOALSTATUS { NOTSTARTED,COMPLETED, ACTIVE };
class GoalDrivenGoal
{
protected:
	MovingEntity* m_entity;
	bool m_started = false;
public:
	GoalDrivenGoal();
	~GoalDrivenGoal();
	virtual void Activiate(MovingEntity*) = 0;
	virtual GOALSTATUS Process(double deltaTime) = 0;
	virtual void Terminate() = 0;
	bool isStarted() { return m_started; };
	virtual bool isCompleted() = 0;
	
};

