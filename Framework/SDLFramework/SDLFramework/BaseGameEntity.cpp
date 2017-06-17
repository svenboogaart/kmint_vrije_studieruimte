#include "BaseGameEntity.h"
#include <SDL.h>
#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "FWApplication.h"

int BaseGameEntity::m_iNextValidId = 1;

void BaseGameEntity::setId()
{
	m_iNextValidId++;
}

BaseGameEntity::BaseGameEntity(double x, double y, int width, int height) :m_ID(m_iNextValidId), m_position(Vector2D(x, y)), m_width(width), m_height(height)
{
	// zorgt ervoor dat elk id uniek is.
	setId();
}

BaseGameEntity::~BaseGameEntity()
{

	if (m_texture)
	{
		FWApplication::GetInstance()->RemoveTexture(m_texture);
	}
}

const int BaseGameEntity::getID()
{
	return m_ID;
}

const bool BaseGameEntity::getTag()
{
	return m_tag;
}

void BaseGameEntity::setTag(const bool value)
{
	m_tag = value;
}

void BaseGameEntity::draw()
{
	if (m_texture)
	{
		int x = m_position.getX();
		int y = m_position.getY();
		FWApplication::GetInstance()->DrawTexture(m_texture, x, y, m_width, m_height);
	}
}

int BaseGameEntity::getWidth()
{
	return m_width;
}

int BaseGameEntity::getHeight()
{
	return m_height;
}

void BaseGameEntity::setPosition(Vector2D newValue)
{
	m_position = newValue;
}

void BaseGameEntity::setX(double x)
{
	m_position.setX(x);
}

void BaseGameEntity::setY(double y)
{
	m_position.setY(y);
}




Vector2D& BaseGameEntity::getPosition()
{
	return m_position;
}

Vector2D BaseGameEntity::getConstPosition() const
{
	return m_position;
}



