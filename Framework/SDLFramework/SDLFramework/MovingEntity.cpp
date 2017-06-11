#include "MovingEntity.h"
#include "SoccerPitch.h"
#include "MovingEntityStates.h"

# define M_PI           3.14159265358979323846  /* pi */



bool MovingEntity::isClosestToBall()
{
	return m_closestToBall;
}

void MovingEntity::setClosestToBall(bool val)
{
	m_closestToBall = val;
}

Vector2D MovingEntity::GetStartPosition()
{
	return m_startPosition;

}

void MovingEntity::Update(double deltaTime)
{
	m_stateMachine->update(deltaTime);
	if(m_lastKick >= 0)
	{
		m_lastKick -= deltaTime;
	}
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

void MovingEntity::KickBall(Vector2D direction)
{
	m_lastKick = 0.8;
}

bool MovingEntity::CanKick()
{
	return (m_lastKick < 0);
}

MovingEntity::MovingEntity(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, SoccerPitch* pitch) :
	m_maxSpeed(maxSpeed),
	m_maxForce(maxForce),
	m_maxTurnRate(maxTurnRate),
	m_mass(mass),
	m_height(height),
	m_width(width),
	m_position(Vector2D(500, 300)),
	m_startPosition(Vector2D(x, y)),
	m_pitch(pitch)
{
	m_velocity = Vector2D(0, 0);
	m_heading = Vector2D(0, 0);
	m_steering = std::make_shared<SteeringBehaviors>(this);
	m_texture = FWApplication::GetInstance()->LoadTexture("pill.png");
	m_stateMachine = std::make_shared<StateMachine<MovingEntity>>(this);
	std::shared_ptr<ReturnState> initialState = std::make_shared<ReturnState>();
	m_stateMachine->setCurrentState(initialState);
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

SoccerPitch * MovingEntity::getPitch()
{
	return m_pitch;
}

void MovingEntity::setVelocity(Vector2D newValue)
{
	m_velocity = newValue;
	//make sure vehicle does not exceed maximum velocity
	m_velocity.truncate(m_maxSpeed);
}

void MovingEntity::setHeading(Vector2D newHeading)
{
	m_heading = newHeading;
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

std::shared_ptr<SteeringBehaviors> MovingEntity::getSteeringBehaviour()
{
	return m_steering;
	
}

std::shared_ptr<StateMachine<MovingEntity>> MovingEntity::getStateMachine()
{
	return m_stateMachine;
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

	if (m_type == EntityType::BALL)
	{
		double friction = 0.05;
		if (!m_velocity.getLength() < deltaTime * friction)
		{
			
			m_velocity = m_velocity * (1 - friction * deltaTime);
		}
	}
	//make sure entity does not exceed maximum velocity
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

	if (m_type == EntityType::BALL)
	{

		if (x < 0 && (y > 230 && y < 370))
		{
			std::cout << "goal left";
			m_pitch->goalScored(LEFT);
		}

		if (x > 1000 && (y > 230 && y < 370))
		{
			std::cout << "goal right";
			m_pitch->goalScored(RIGHT);
		}
	}


	if (x > 1000)
	{
		m_velocity.setX(-m_velocity.getX());
		m_position.setX(1000);
	}
	else if (x < -0)
	{
		m_velocity.setX(-m_velocity.getX());
		m_position.setX(0);
	}

	if (y > 600)
	{
		m_velocity.setY(-m_velocity.getY());
		m_position.setY(600);
	}
	else if (y < -0)
	{
		m_velocity.setY(-m_velocity.getY());
		m_position.setY(0);
	}
}