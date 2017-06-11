#include "GoalKeeper.h"



GoalKeeper::GoalKeeper(Vector2D initialPosition, SoccerPitch* pitch,  SoccerTeam* team)
	:PlayerBase(initialPosition,pitch, team)
{
	m_texture = FWApplication::GetInstance()->LoadTexture("keeper.png");

	m_type = EntityType::GOALY;
	
}