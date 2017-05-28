#pragma once
#include "FWApplication.h"
#include "SoccerBall.h"
class SoccerPitch
{

private:
	SDL_Texture* m_texture;
	SoccerBall& m_ball;
public:
	SoccerPitch();
	~SoccerPitch();
	void Update(double deltaTime);
	void Render();
};

