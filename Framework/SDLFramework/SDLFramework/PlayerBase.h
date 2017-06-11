#pragma once
#include "MovingEntity.h"
#include "Vector2D.h"
class SoccerTeam;
class PlayerBase :public MovingEntity
{
private:
	SoccerTeam * m_team;
public:
	SoccerTeam * getTeam();
	PlayerBase(Vector2D initialPosition, SoccerPitch* pitch, SoccerTeam* team);
	bool CanPassForward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool CanPassBackward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool WithingShootingRange();
	bool AtTarget();
	bool IsReadyForKick();
};

