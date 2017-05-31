#include "SoccerPitch.h"



SoccerPitch::SoccerPitch()
{
	m_texture = FWApplication::GetInstance()->LoadTexture("pitch.jpg");
	m_ball = new SoccerBall(500, 300, 40, 40, 10, 100, 100, 100);
	SDL_Texture* redTeamTexture = FWApplication::GetInstance()->LoadTexture("blueplayer.png");
	SDL_Texture* blueTeamTexture = FWApplication::GetInstance()->LoadTexture("redplayer.png");
	m_redTeam = new SoccerTeam(Vector2D(900, 300), Vector2D(720, 100), Vector2D(750, 500), Vector2D(550, 150), Vector2D(550, 450), redTeamTexture);
	m_blueTeam = new SoccerTeam(Vector2D(60, 300), Vector2D(220, 220), Vector2D(220, 380), Vector2D(450, 50), Vector2D(450, 550), blueTeamTexture);
}

SoccerPitch::~SoccerPitch()
{
	delete m_ball;
}

void SoccerPitch::Update(double deltaTime)
{
	m_ball->Update(deltaTime);
	m_redTeam->Update(deltaTime);
	m_blueTeam->Update(deltaTime);
}

void SoccerPitch::Render()
{
	if (m_texture != nullptr)
	{
		FWApplication::GetInstance()->DrawTexture(m_texture, 500,300,1000,600);
	}
	m_ball->Render();
	m_redTeam->Render();
	m_blueTeam->Render();
}


