#pragma once
#include "State.h"
class MovingEntity;

class ReturnState : public State<MovingEntity>
{
public:

	// Inherited via State
	virtual void enter(MovingEntity*) override;

	virtual void execute(MovingEntity*, double deltaTime) override;

	virtual void exit(MovingEntity*) override;
	virtual std::string name() override;

};

class WaitState : public State<MovingEntity>
{
public:

	// Inherited via State
	virtual void enter(MovingEntity*) override;

	virtual void execute(MovingEntity*, double deltaTime) override;

	virtual void exit(MovingEntity*) override;
	virtual std::string name() override;

};

