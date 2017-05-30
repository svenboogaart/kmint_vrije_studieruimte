#include "SoccerPitch.h"



SoccerPitch::SoccerPitch():
	m_ball(&SoccerBall(0,0,40,40,10,100,100,100)), 
	m_readTeam(&SoccerTeam(Vector2D(10, 500), Vector2D(100, 200), Vector2D(100, 800), Vector2D(400, 150), Vector2D(400, 750))),
		m_blueTeam(&SoccerTeam(Vector2D(10, 500), Vector2D(100, 200), Vector2D(100, 800), Vector2D(400, 150), Vector2D(400, 750)))

{
	m_texture = FWApplication::GetInstance()->LoadTexture("pitch.jpg");
}

SoccerPitch::~SoccerPitch()
{
	//delete m_ball;
}

void SoccerPitch::Update(double deltaTime)
{
	m_ball->Update(deltaTime);
	//m_readTeam->Update(deltaTime);
	//m_blueTeam->Update(deltaTime);
}

void SoccerPitch::Render()
{
	if (m_texture != nullptr)
	{
		FWApplication::GetInstance()->DrawTexture(m_texture, 500,300,1000,600);
	}
	m_ball->Render();
	//m_readTeam->Render();
	//m_blueTeam->Render();
}


