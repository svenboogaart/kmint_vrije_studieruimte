#pragma once
#include "Vector2D.h"
#include "MovingEntity.h"
class Vehicle;
class SteeringBehaviors
{
private:
	MovingEntity* m_entity;

	//radius van de wander circel
	double m_wanderRadius;

	//afstand dat de wander circel van de auto is
	double m_wanderDistance;

	//Finally, m_dWanderJitter is the maximum amount of random displacement
	//that can be added to the target each second
	double m_wanderJitter;
	Vector2D m_wanderTarget;
public:
	SteeringBehaviors(MovingEntity*);


	Vector2D calculate();
	Vector2D seek(Vector2D);
	Vector2D flee(Vector2D);
	Vector2D arrive(Vector2D);
	Vector2D wander();
	Vector2D pursuit(MovingEntity* evader);
	Vector2D seperation();
	Vector2D allignment();
	Vector2D Cohesion();
	double GenerateRandom(double, double);
};
