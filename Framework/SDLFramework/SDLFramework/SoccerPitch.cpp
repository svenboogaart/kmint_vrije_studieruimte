#include "SoccerPitch.h"



SoccerPitch::SoccerPitch():m_ball(*new SoccerBall(0,0,40,40,10,100,100,100))
{
	m_texture = FWApplication::GetInstance()->LoadTexture("pitch.jpg");
}

SoccerPitch::~SoccerPitch()
{
	//delete m_ball;
}

void SoccerPitch::Update(double deltaTime)
{
	m_ball.Update(deltaTime);
}

void SoccerPitch::Render()
{
	if (m_texture != nullptr)
	{
		FWApplication::GetInstance()->DrawTexture(m_texture, 500,300,1000,600);
	}
	m_ball.Render();
}


