#include "SteeringBehaviors.h"
#include <random>
#include <time.h>       
#include "MovingEntity.h"

SteeringBehaviors::SteeringBehaviors(MovingEntity* vehicle) :m_wanderDistance(200), m_wanderJitter(10), m_wanderRadius(100), m_wanderTarget(Vector2D(GenerateRandom(-1, 1), GenerateRandom(-1, 1)))
{
	m_entity = vehicle;
}

Vector2D SteeringBehaviors::calculate()
{
	return Vector2D(0, 0);
}

Vector2D SteeringBehaviors::seek(Vector2D targetPos)
{
	Vector2D DesiredVelocity = (targetPos - m_entity->getPosition()).normalized() * m_entity->getMaxSpeed();
	return (DesiredVelocity - m_entity->getVelocity());
}

Vector2D SteeringBehaviors::flee(Vector2D targetPos)
{
	Vector2D DesiredVelocity = (m_entity->getPosition() - targetPos).normalized() * m_entity->getMaxSpeed();
	return (DesiredVelocity - m_entity->getVelocity());
}

Vector2D SteeringBehaviors::arrive(Vector2D destination)
{
	//{slow = 3, normal = 2, fast = 1}
	int deceleration = 1;
	Vector2D toTarget = destination - m_entity->getPosition();

	//afstand naar doelwit
	double distance = toTarget.getLength();
	if (distance < 2)
	{
		distance = 2;
	}

	//Als hij niet geariveerd is
	if (distance > 0)
	{
		const double decelerationTweaker = 0.3;

		double speed = distance / deceleration*decelerationTweaker;

		if (speed > m_entity->getMaxSpeed())
		{
			speed = m_entity->getMaxSpeed();
		}

		Vector2D desiredVelocity = (toTarget * speed / distance)*2;

		return(desiredVelocity - m_entity->getVelocity());
	}
	return Vector2D(0, 0);
}

Vector2D SteeringBehaviors::wander()
{




	//first, add a small random vector to the target’s position (RandomClamped
	//returns a value between -1 and 1)
	m_wanderTarget += Vector2D(GenerateRandom(-1, 1) * m_wanderJitter,
		GenerateRandom(-1, 1) * m_wanderJitter);

	//reproject this new vector back onto a unit circle
	m_wanderTarget.normalized();

	//increase the length of the vector to the same as the radius
	//of the wander circle
	m_wanderTarget *= m_wanderRadius;

	//move the target into a position WanderDist in front of the agent
	Vector2D targetLocal = m_wanderTarget + Vector2D(m_wanderDistance, 0);

	//project the target into world space


	/* !!!!
	Vector2D targetWorld = PointToWorldSpace(targetLocal,
	m_pVehicle->Heading(),
	m_pVehicle->Side(),
	m_pVehicle->Pos());
	*/
	//and steer toward it
	//return targetWorld - m_pVehicle->Pos();
	return  m_entity->getPosition();




	return Vector2D(12, 4);
}

Vector2D SteeringBehaviors::pursuit(MovingEntity* evader)
{
	Vector2D toEvader = evader->getPosition() - m_entity->getPosition();
	double lookAheadTime = 1;
	if (toEvader.getLength() > 2)
	{
		lookAheadTime = toEvader.getLength() / (m_entity->getMaxSpeed() + evader->getVelocity().getLength());
	}
	return seek(evader->getPosition() + evader->getVelocity() * lookAheadTime);
}

Vector2D SteeringBehaviors::seperation()
{
	const double range = 150;
	Vector2D steeringForce = Vector2D(0, 0);
	/*bool set = false;
	for (auto& value : m_entity->getNeighbours(range))
	{
		Vector2D toAgent = m_entity->getPosition() - value->getPosition();
		if (!set)
		{
			steeringForce = toAgent.normalized() / toAgent.getLength();
			set = true;
		}
		else
		{

			steeringForce += toAgent.normalized() / toAgent.getLength();
		}

	}*/
	return steeringForce;
}

Vector2D SteeringBehaviors::allignment()
{
	const int range = 150;
	Vector2D averageHeading = Vector2D(0, 0);
	/*bool set = false;
	for (auto& value : m_entity->getNeighbours(range))
	{
		if (!set)
		{
			averageHeading = value->getHeading();
			set = true;
		}
		else
		{

			averageHeading += value->getHeading();
		}
	}
	if (!set)
	{
		return Vector2D(0, 0);
	}

	int amountNeighbours = m_entity->getNeighbours(range).size();
	averageHeading = averageHeading / (double)amountNeighbours;*/
	return averageHeading;
}

Vector2D SteeringBehaviors::Cohesion()
{
	const int range = 150;
	Vector2D centerOfMass = Vector2D(0, 0);


	/*bool set = false;

	int amountNeighbours = 0;
	for (auto& value : m_entity->getNeighbours(range))
	{
		if (!set)
		{
			centerOfMass = value->getHeading();
			set = true;
		}
		else
		{

			centerOfMass += value->getHeading();
		}
		amountNeighbours++;
	}
	if (!set)
	{
		return Vector2D(0, 0);
	}
	centerOfMass = centerOfMass / amountNeighbours;*/
	return seek(centerOfMass);

}


double SteeringBehaviors::GenerateRandom(double min, double max)
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL));
		first = false;
	}
	if (min > max)
	{
		std::swap(min, max);
	}
	return min + (double)rand() * (max - min) / (double)RAND_MAX;
}


