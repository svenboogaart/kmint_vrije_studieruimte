#include "SoccerTeam.h"
#include "GoalKeeper.h"
#include "FieldPlayer.h"
#include <memory>
#include <algorithm>
#include "MovingEntityStates.h"

SoccerTeam::SoccerTeam(Vector2D goalyPosition, Vector2D defenderOnePosition, Vector2D defenderTwoPosition, Vector2D attackerOnePosition, Vector2D attackerTwoPosition, SDL_Texture* _m_texture, SoccerPitch* pitch)
{
	players.push_back( new GoalKeeper(goalyPosition,pitch));
	players.push_back( new FieldPlayer(defenderOnePosition,_m_texture, pitch));
	players.push_back(new FieldPlayer(defenderTwoPosition, _m_texture, pitch));
	players.push_back(new FieldPlayer(attackerOnePosition, _m_texture, pitch));
	players.push_back(new FieldPlayer(attackerTwoPosition, _m_texture, pitch));
	std::shared_ptr<ChaseState> initialState = std::make_shared<ChaseState>();
	players.back()->getStateMachine()->changeState(initialState);

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

void SoccerTeam::AddGoal()
{
	m_points++;
}

int SoccerTeam::GetScore()
{
	return m_points;
}

void SoccerTeam::SetState(EntityStates state)
{
	if (state == RETURNSTATE)
	{
		for (PlayerBase* player : players) {
			std::shared_ptr<ReturnState> initialState = std::make_shared<ReturnState>();
			players.back()->getStateMachine()->changeState(initialState);
		}
		
	}
}

