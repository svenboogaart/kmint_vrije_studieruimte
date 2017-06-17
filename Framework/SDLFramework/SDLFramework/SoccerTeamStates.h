#pragma once

#include "State.h"
class SoccerTeam;

class PrepareForKickoffState : public State<SoccerTeam>
{
public:

	// Inherited via State
	virtual void enter(SoccerTeam*) override;

	virtual void execute(SoccerTeam*, double deltaTime) override;

	virtual void exit(SoccerTeam*) override;
	virtual std::string name() override;

};


class DefendState : public State<SoccerTeam>
{
public:

	// Inherited via State
	virtual void enter(SoccerTeam*) override;

	virtual void execute(SoccerTeam*, double deltaTime) override;

	virtual void exit(SoccerTeam*) override;
	virtual std::string name() override;

};

class AttackState : public State<SoccerTeam>
{
public:

	// Inherited via State
	virtual void enter(SoccerTeam*) override;

	virtual void execute(SoccerTeam*, double deltaTime) override;

	virtual void exit(SoccerTeam*) override;
	virtual std::string name() override;

};