#pragma once
#include "PlayerBase.h"
#include "Vector2D.h"
#include "Vector2D.h"
#include <vector>
enum EntityStates{RETURNSTATE};
class SoccerTeam
{
private:
	std::vector<PlayerBase*> players;
	PlayerBase* m_receivingPlayer;
	PlayerBase* m_playerClosestToBall;
	PlayerBase* m_controllingPlayer;
	int m_points;

public:
	SoccerTeam(Vector2D goalyPosition, Vector2D defenderOnePosition, Vector2D defenderTwoPosition, Vector2D attackerOnePosition, Vector2D attackerTwoPosition, SDL_Texture* _m_texture, SoccerPitch* pitch);
	
	void Update(double detlaTime);
	void Render();
	bool CanShoot(Vector2D from, Vector2D to, Vector2D heading, double power);
	void RequestPass(PlayerBase*);
	void AddGoal();
	int GetScore();
	void SetState(EntityStates state);

};

