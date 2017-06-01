#pragma once
#include "FWApplication.h"
#include "SoccerBall.h"
#include "SoccerTeam.h"

class SoccerPitch
{

private:
	SDL_Texture* m_texture;
	SoccerBall * m_ball;

	SoccerTeam * m_redTeam;
	SoccerTeam * m_blueTeam;
public:
	SoccerPitch();
	~SoccerPitch();
	void Update(double deltaTime);
	void Render();
	SoccerBall * getBall();
};

