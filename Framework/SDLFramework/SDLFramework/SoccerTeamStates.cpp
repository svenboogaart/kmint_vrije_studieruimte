#include "SoccerTeamStates.h"
#include "SoccerTeam.h"
#include "SoccerPitch.h"
void PrepareForKickoffState::enter(SoccerTeam * team)
{
	team->SetControllingPlayer(nullptr);
	team->SetReceivingPlayer(nullptr);
	team->SetSupportingPlayer(nullptr);
	team->SetClosestToBall(nullptr);
}

void PrepareForKickoffState::execute(SoccerTeam * team, double deltaTime)
{
	SoccerPitch * pitch = team->getPitch();
	if (pitch->EveryBodyIsHome())
	{

	}
}

void PrepareForKickoffState::exit(SoccerTeam *)
{
}

std::string PrepareForKickoffState::name()
{
	return std::string();
}

void DefendState::enter(SoccerTeam * team)
{
	team->SetDefendingPositions();
}

void DefendState::execute(SoccerTeam * team, double deltaTime)
{
	if (team->IsInControl())
	{
		team->SetState(std::make_shared<AttackState>());
	}
}

void DefendState::exit(SoccerTeam *)
{
}

std::string DefendState::name()
{
	return std::string();
}

void AttackState::enter(SoccerTeam * team)
{
	team->SetAttackingPositions();
}

void AttackState::execute(SoccerTeam * team, double deltaTime)
{
	if (!team->IsInControl())
	{
		team->SetState(std::make_shared<DefendState>());
	}
	//team->determinBestSupportingPosition();
}

void AttackState::exit(SoccerTeam *)
{
}

std::string AttackState::name()
{
	return std::string();
}
