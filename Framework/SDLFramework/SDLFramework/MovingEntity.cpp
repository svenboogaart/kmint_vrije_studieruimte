#include "MovingEntity.h"

# define M_PI           3.14159265358979323846  /* pi */




void MovingEntity::Update(double deltaTime)
{
}

void MovingEntity::Render()
{
	if (m_texture)
	{
		int x = m_position.getX();
		int y = m_position.getY();
		FWApplication::GetInstance()->DrawTexture(m_texture, x, y, m_width, m_height, getAngle(), getDirection());
	}
}

bool MovingEntity::voidHandleMessage(Telegram telegram)
{
	return false;
}

MovingEntity::MovingEntity(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate) :
	m_maxSpeed(maxSpeed),
	m_maxForce(maxForce),
	m_maxTurnRate(maxTurnRate),
	m_mass(mass),
	m_height(height),
	m_width(width),
	m_position (Vector2D(x, y))
{
	m_velocity = Vector2D(0, 0);
	m_heading = Vector2D(0, 0);
	
	m_texture = FWApplication::GetInstance()->LoadTexture("pitch.jpg");
}

MovingEntity::~MovingEntity()
{
	if (m_texture)
	{
		FWApplication::GetInstance()->RemoveTexture(m_texture);
	}
}

double MovingEntity::getMaxSpeed()
{
	return m_maxSpeed;
}

Vector2D MovingEntity::getPosition()
{
	return m_position;
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


void MovingEntity::move(Vector2D influence, double deltaTime)
{
	Vector2D steeringForce = influence;


	// acceleration = Force/Mass
	Vector2D acceleration = steeringForce / m_mass;


	m_velocity += acceleration * deltaTime;

	//make sure vehicle does not exceed maximum velocity
	m_velocity.truncate(m_maxSpeed);


	//update the position
	m_position += m_velocity * deltaTime;

	if (m_velocity.getLength() > 0, 00000001)
	{
		m_heading = m_velocity.normalized();
	}

	FWApplication::GetInstance()->SetColor(Color(50, 50, 255, 255));
	//wrapAround

	double x = m_position.getX();
	double y = m_position.getY();

	if (x > 610)
	{
		m_position.setX(x - 610);
	}
	else if (x < -10)
	{
		m_position.setX(x + 610);
	}

	if (y > 610)
	{
		m_position.setY(y - 610);
	}
	else if (y < -10)
	{
		m_position.setY(y + 610);
	}
}