#pragma once
#include "PlayerBase.h"
#include "Vector2D.h"
#include "Vector2D.h"
#include <vector>
class SoccerTeam
{
private:
	std::vector<PlayerBase*> players;
	PlayerBase* m_receivingPlayer;
	PlayerBase* m_playerClosestToBall;
	PlayerBase* m_controllingPlayer;

public:
	SoccerTeam(Vector2D goalyPosition, Vector2D defenderOnePosition, Vector2D defenderTwoPosition, Vector2D attackerOnePosition, Vector2D attackerTwoPosition);
	void Update(double detlaTime);
	void Render();
	bool CanShoot(Vector2D from, Vector2D to, Vector2D heading, double power);
	void RequestPass(PlayerBase*);
};

