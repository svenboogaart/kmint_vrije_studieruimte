#pragma once
#include "PlayerBase.h"
#include "Vector2D.h"
class SoccerTeam
{
public:
	SoccerTeam();
	void Update(double detlaTime);
	void Render();
	bool CanShoot(Vector2D from, Vector2D to, Vector2D heading, double power);
	void RequestPass(PlayerBase*);
};

