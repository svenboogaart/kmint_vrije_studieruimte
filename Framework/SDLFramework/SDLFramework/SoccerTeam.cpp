#include "SoccerTeam.h"
#include "GoalKeeper.h"
#include "FieldPlayer.h"
#include <memory>
#include <algorithm>
#include "MovingEntityStates.h"
#include "SoccerPitch.h"
#include "SoccerTeamStates.h"

SoccerTeam::SoccerTeam(Vector2D goalyPosition, Vector2D defenderOnePosition, Vector2D defenderTwoPosition, Vector2D attackerOnePosition, Vector2D attackerTwoPosition, SDL_Texture* _m_texture, SoccerPitch* pitch, double goalTarget, TEAMCOLOR color)
{
	m_goalTarget = goalTarget;
	m_color = color;
	m_pitch = pitch;
	players.push_back( new GoalKeeper(goalyPosition,pitch,this));
	players.push_back( new FieldPlayer(defenderOnePosition,_m_texture, pitch, this));
	players.push_back(new FieldPlayer(defenderTwoPosition, _m_texture, pitch, this));
	players.push_back(new FieldPlayer(attackerOnePosition, _m_texture, pitch, this));
	players.push_back(new FieldPlayer(attackerTwoPosition, _m_texture, pitch, this));
	std::shared_ptr<ChaseState> initialState = std::make_shared<ChaseState>();
	players.back()->getStateMachine()->changeState(initialState);
	
	//set team state
	m_stateMachine = std::make_shared<StateMachine<SoccerTeam>>(this);
	std::shared_ptr<DefendState> teamstate = std::make_shared<DefendState>();
	m_stateMachine->setCurrentState(teamstate);
}

void SoccerTeam::setInControl(bool control)
{
	m_inControl = control;
}

bool SoccerTeam::IsInControl()
{
	return m_inControl;
}

void SoccerTeam::Update(double detlaTime)
{	
	if (!m_playerClosestToBall)
	{
		m_playerClosestToBall = players.back();
	}
	Vector2D position = m_pitch->getBall()->getPosition();
	for (PlayerBase* player : players) {

		//calculate the player closest to the ball
		if (player != m_playerClosestToBall)
		{
			player->setClosestToBall(false);
			if (player->getPosition().distanceTo(position) < m_playerClosestToBall->getPosition().distanceTo(position))
			{
				m_playerClosestToBall = player;
				player->setClosestToBall(true);
			}
		}
		
		player->Update(detlaTime);
	}
	m_stateMachine->update(detlaTime);
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

bool SoccerTeam::EveryoneIsHome()
{
	for (PlayerBase* player : players) 
	{
		if (!player->IsHome())
		{
			return false;
		}
	}
	return true;
}

void SoccerTeam::SetControllingPlayer(PlayerBase * player)
{
	m_controllingPlayer = player;
}

void SoccerTeam::SetState(std::shared_ptr<State<SoccerTeam>> state)
{
}

void SoccerTeam::SetReceivingPlayer(PlayerBase * player)
{
	m_receivingPlayer = player;

}

void SoccerTeam::SetSupportingPlayer(PlayerBase *player)
{
	m_supportingPlayer = player;
}

void SoccerTeam::SetClosestToBall(PlayerBase * player)
{
	m_playerClosestToBall = player;
}

void SoccerTeam::ReturnAllHome()
{
	for (PlayerBase* player : players) {
		std::shared_ptr<ReturnState> nextState = std::make_shared<ReturnState>();
		player->SetState(nextState);
	}
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

void SoccerTeam::SetAttackingPositions()
{
	for (PlayerBase* player : players) {
		player->setAttackingPosition();
	}
}

void SoccerTeam::SetDefendingPositions()
{
	for (PlayerBase* player : players) {
		player->setDefendingPosition();
	}
}

SoccerPitch * SoccerTeam::getPitch()
{
	return m_pitch;
}

TEAMCOLOR SoccerTeam::getColor()
{
	return m_color;
}

