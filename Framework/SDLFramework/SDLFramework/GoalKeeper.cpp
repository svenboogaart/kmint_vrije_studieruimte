#include "GoalKeeper.h"



GoalKeeper::GoalKeeper(Vector2D initialPosition, SoccerPitch* pitch)
	:PlayerBase(initialPosition,pitch)
{
	m_texture = FWApplication::GetInstance()->LoadTexture("keeper.png");

	m_type = EntityType::GOALY;
	
}