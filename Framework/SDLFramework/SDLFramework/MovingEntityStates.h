#pragma once
#include "State.h"
class PlayerBase;
class FieldPlayer;

class ReturnState : public State<PlayerBase>
{
public:

	// Inherited via State
	virtual void enter(PlayerBase*) override;

	virtual void execute(PlayerBase*, double deltaTime) override;

	virtual void exit(PlayerBase*) override;
	virtual std::string name() override;

};

class WaitState : public State<PlayerBase>
{
public:

	// Inherited via State
	virtual void enter(PlayerBase*) override;

	virtual void execute(PlayerBase*, double deltaTime) override;

	virtual void exit(PlayerBase*) override;
	virtual std::string name() override;

};

class TestState : public State<PlayerBase>
{
public:

	// Inherited via State
	virtual void enter(PlayerBase*) override;

	virtual void execute(PlayerBase*, double deltaTime) override;

	virtual void exit(PlayerBase*) override;
	virtual std::string name() override;

};


class ChaseState : public State<PlayerBase>
{
public:

	// Inherited via State
	virtual void enter(PlayerBase*) override;

	virtual void execute(PlayerBase*, double deltaTime) override;

	virtual void exit(PlayerBase*) override;
	virtual std::string name() override;

};


class KickState : public State<PlayerBase>
{
public:

	// Inherited via State
	virtual void enter(PlayerBase*) override;

	virtual void execute(PlayerBase*, double deltaTime) override;

	virtual void exit(PlayerBase*) override;
	virtual std::string name() override;

};


class ReceiveState : public State<PlayerBase>
{
public:

	// Inherited via State
	virtual void enter(PlayerBase*) override;

	virtual void execute(PlayerBase*, double deltaTime) override;

	virtual void exit(PlayerBase*) override;
	virtual std::string name() override;

};





