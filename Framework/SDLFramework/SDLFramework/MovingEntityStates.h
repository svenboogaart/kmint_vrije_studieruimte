#pragma once
#include "State.h"
class MovingEntity;
class FieldPlayer;

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

class TestState : public State<MovingEntity>
{
public:

	// Inherited via State
	virtual void enter(MovingEntity*) override;

	virtual void execute(MovingEntity*, double deltaTime) override;

	virtual void exit(MovingEntity*) override;
	virtual std::string name() override;

};


class ChaseState : public State<MovingEntity>
{
public:

	// Inherited via State
	virtual void enter(MovingEntity*) override;

	virtual void execute(MovingEntity*, double deltaTime) override;

	virtual void exit(MovingEntity*) override;
	virtual std::string name() override;

};


class KickState : public State<FieldPlayer>
{
public:

	// Inherited via State
	virtual void enter(FieldPlayer*) override;

	virtual void execute(FieldPlayer*, double deltaTime) override;

	virtual void exit(FieldPlayer*) override;
	virtual std::string name() override;

};



