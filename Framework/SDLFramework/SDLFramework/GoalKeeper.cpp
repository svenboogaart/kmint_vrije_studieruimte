#include "GoalKeeper.h"



GoalKeeper::GoalKeeper(Vector2D initialPosition)
	:PlayerBase(initialPosition)
{
	m_texture = FWApplication::GetInstance()->LoadTexture("keeper.png");
	
	
}