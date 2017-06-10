#include "SoccerPitch.h"



void SoccerPitch::PrintScore()
{
	std::cout << "Goal scored " << m_redTeam->GetScore() << "-" << m_blueTeam->GetScore() << std::endl;
}

SoccerPitch::SoccerPitch()
{
	m_texture = FWApplication::GetInstance()->LoadTexture("pitch.png");
	m_ball = new SoccerBall(500, 300, 40, 40, 2, 210, 230, 300, this);
	SDL_Texture* redTeamTexture = FWApplication::GetInstance()->LoadTexture("blueplayer.png");
	SDL_Texture* blueTeamTexture = FWApplication::GetInstance()->LoadTexture("redplayer.png");
	m_redTeam = new SoccerTeam( Vector2D(900, 300), Vector2D(720, 100), Vector2D(750, 500), Vector2D(550, 150), Vector2D(550, 450), redTeamTexture, this);
	m_blueTeam = new SoccerTeam( Vector2D(60, 300), Vector2D(220, 220), Vector2D(220, 380), Vector2D(450, 50), Vector2D(450, 550), blueTeamTexture, this);
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

SoccerBall * SoccerPitch::getBall()
{
	return m_ball;
}

void SoccerPitch::goalScored(GOAL position)
{
	if (position == GOAL::RIGHT)
	{
		m_redTeam->AddGoal();
	}
	else
	{
		m_blueTeam->AddGoal();
	}
	//m_redTeam->SetState(RETURNSTATE);
	//m_blueTeam->SetState(RETURNSTATE);
	PrintScore();
}

//a goal has be scored, lets start the next round.
void SoccerPitch::startRound()
{

}


