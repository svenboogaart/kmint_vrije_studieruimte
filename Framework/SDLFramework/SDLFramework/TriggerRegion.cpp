#include "TriggerRegion.h"



TriggerRegion::TriggerRegion(Vector2D position, SDL_Texture* texture, int width, int height)
{
	m_position = position;
	m_texture = texture;
	m_width = width;
	m_height = height;
		 
}


TriggerRegion::~TriggerRegion()
{
}

bool TriggerRegion::isTouching(Vector2D position, double radius)
{
	return m_position.distanceTo(position) < radius* radius;
}

void TriggerRegion::Render()
{
	if (m_texture)
	{
		int x = m_position.getX();
		int y = m_position.getY();
		FWApplication::GetInstance()->DrawTexture(m_texture, x, y, m_width, m_height);
	}
}

void TriggerRegion::ChangePosition(Vector2D position)
{
	m_position = position;
}
