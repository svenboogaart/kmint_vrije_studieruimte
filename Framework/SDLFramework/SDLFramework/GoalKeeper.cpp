#include "GoalKeeper.h"



GoalKeeper::GoalKeeper(Vector2D initialPosition, SoccerPitch* pitch,  SoccerTeam* team)
	:PlayerBase(initialPosition,pitch, team)
{
	m_position = initialPosition;
	m_texture = FWApplication::GetInstance()->LoadTexture("keeper.png");
	m_attackPosition = initialPosition;
	m_targetPosition = initialPosition;
	m_type = EntityType::GOALY;
	
}