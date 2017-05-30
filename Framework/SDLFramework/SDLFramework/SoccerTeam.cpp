#include "SoccerTeam.h"
#include "GoalKeeper.h"
#include "FieldPlayer.h"
#include <memory>
#include <algorithm>


SoccerTeam::SoccerTeam(Vector2D goalyPosition, Vector2D defenderOnePosition, Vector2D defenderTwoPosition, Vector2D attackerOnePosition, Vector2D attackerTwoPosition)
{
	players.push_back(&GoalKeeper(goalyPosition));
	players.push_back(&FieldPlayer(defenderOnePosition));
	players.push_back(&FieldPlayer(defenderTwoPosition));
	players.push_back(&FieldPlayer(attackerOnePosition));
	players.push_back(&FieldPlayer(attackerTwoPosition));

}

void SoccerTeam::Update(double detlaTime)
{
	for (PlayerBase* player : players) {
		player->Update(detlaTime);
	}
}

void SoccerTeam::Render()
{
	for (PlayerBase* player : players) {
		player->Render();
	}
}

bool SoccerTeam::CanShoot(Vector2D from, Vector2D to, Vector2D heading, double power)
{
	return false;
}

void SoccerTeam::RequestPass(PlayerBase *)
{
}

