#pragma once
#include "BaseGameEntity.h"

class MovingEntity : public BaseGameEntity
{
protected:
	//richtings vector geeft de snelheid en richtings aan.
	Vector2D m_velocity;
	Vector2D m_heading;

	double m_mass;
	const double m_maxSpeed;
	const double m_maxForce;
	const double m_maxTurnRate;


public:
	MovingEntity(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate);
	double getMaxSpeed();
	Vector2D getVelocity();
	Vector2D getHeading();
	void setVelocity(Vector2D);
	void calculateHeading();
	double getAngle();
	//Tegenovergestelde vector van de richtings vector (velocity)
	Vector2D m_side();
	double getMass();
	void draw() override;
	int getDirection();
};
