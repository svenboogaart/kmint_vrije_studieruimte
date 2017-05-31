#include "SoccerTeam.h"
#include "GoalKeeper.h"
#include "FieldPlayer.h"
#include <memory>
#include <algorithm>


SoccerTeam::SoccerTeam(Vector2D goalyPosition, Vector2D defenderOnePosition, Vector2D defenderTwoPosition, Vector2D attackerOnePosition, Vector2D attackerTwoPosition, SDL_Texture* _m_texture)
{
	players.push_back( new GoalKeeper(goalyPosition));
	players.push_back( new FieldPlayer(defenderOnePosition,_m_texture));
	players.push_back(new FieldPlayer(defenderTwoPosition, _m_texture));
	players.push_back(new FieldPlayer(attackerOnePosition, _m_texture));
	players.push_back(new FieldPlayer(attackerTwoPosition, _m_texture));

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

