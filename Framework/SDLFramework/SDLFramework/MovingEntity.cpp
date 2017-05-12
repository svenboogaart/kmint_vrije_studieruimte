#include "MovingEntity.h"

# define M_PI           3.14159265358979323846  /* pi */


MovingEntity::MovingEntity(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate)
	:BaseGameEntity(x, y, width, height),
	m_maxSpeed(maxSpeed), m_maxForce(maxForce), m_maxTurnRate(maxTurnRate), m_mass(mass)
{
	m_velocity = Vector2D(0, 0);
	m_heading = Vector2D(0, 0);
}

double MovingEntity::getMaxSpeed()
{
	return m_maxSpeed;
}

Vector2D MovingEntity::getVelocity()
{
	return m_velocity;
}

Vector2D MovingEntity::getHeading()
{
	calculateHeading();
	return m_heading;
}

void MovingEntity::setVelocity(Vector2D newValue)
{
	m_velocity = newValue;
	//make sure vehicle does not exceed maximum velocity
	m_velocity.truncate(m_maxSpeed);
}

void MovingEntity::calculateHeading()
{

	m_heading = m_velocity.normalized();
	if (m_velocity.getX() == 0 && m_velocity.getY() == 0)
	{
		m_heading = Vector2D(0, 0);
	}
}

double MovingEntity::getAngle()
{
	double angleRadians = std::atan2(getHeading().getY(), getHeading().getX());
	double angleDegrees = (angleRadians / M_PI) * 180;
	return angleDegrees;
}


Vector2D MovingEntity::m_side()
{
	return m_heading.opposite();
}

double MovingEntity::getMass()
{
	return m_mass;
}

void MovingEntity::draw()
{
	if (m_texture)
	{
		int x = m_position.getX();
		int y = m_position.getY();
		FWApplication::GetInstance()->DrawTexture(m_texture, x, y, m_width, m_height, getAngle(), getDirection());
	}
}

int MovingEntity::getDirection()
{
	if (m_heading.getX() > 0)
	{
		return 1;
	}
	if (m_heading.getX() < 0)
	{
		return -1;
	}

	return 0;
}


