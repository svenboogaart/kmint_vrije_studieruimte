#pragma once
#include "Vector2D.h"
#include "Telegram.h"
#include "FWApplication.h"
#include "StateMachine.h"
#include <memory>
#include "SteeringBehaviors.h"

class MovingEntity
{
protected:
	//richtings vector geeft de snelheid en richtings aan.
	Vector2D m_velocity;
	Vector2D m_heading;
	SDL_Texture* m_texture;
	double m_mass;
	double m_maxSpeed;
	double m_maxForce;
	double m_maxTurnRate;
	
	Vector2D  m_position;
	int m_width;
	int m_height;
	std::shared_ptr<StateMachine<MovingEntity>> m_stateMachine;
	std::shared_ptr<SteeringBehaviors> m_steering;
	Vector2D  m_startPosition;
public:
	Vector2D GetStartPosition();
	void Update(double deltaTime);
	void Render();
	bool voidHandleMessage(Telegram telegram);

	MovingEntity(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate);
	~MovingEntity();
	double getMaxSpeed();
	Vector2D getPosition();
	Vector2D getVelocity();
	Vector2D getHeading();
	void setVelocity(Vector2D);
	void calculateHeading();
	double getAngle();
	std::shared_ptr<SteeringBehaviors> getSteeringBehaviour();
	std::shared_ptr<StateMachine<MovingEntity>> getStateMachine();
	//Tegenovergestelde vector van de richtings vector (velocity)
	Vector2D m_side();
	double getMass();
	int getDirection();
	void move(Vector2D influence, double deltaTime);
};
