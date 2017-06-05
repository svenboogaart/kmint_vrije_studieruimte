#include "MovingEntityStates.h"
#include "MovingEntity.h"
#include "SteeringBehaviors.h"
#include <memory>
#include "SoccerPitch.h"

#pragma region ReturnState
void ReturnState::enter(MovingEntity * ball)
{
}

void ReturnState::execute(MovingEntity * ball , double deltaTime)
{
	Vector2D target = ball->GetStartPosition();
	ball->move(ball->getSteeringBehaviour()->arrive(target),deltaTime);
	if (ball->getPosition().distanceTo(target) < 5)
	{
		std::shared_ptr<WaitState> nextState = std::make_shared<WaitState>();
		ball->getStateMachine()->changeState(nextState);
	}
}

void ReturnState::exit(MovingEntity * ball)
{
}

std::string ReturnState::name()
{
	return "Return state";
}
#pragma endregion ReturnState

#pragma region WaitState
void WaitState::enter(MovingEntity *)
{

}

void WaitState::execute(MovingEntity *, double deltaTime)
{

}

void WaitState::exit(MovingEntity *)
{

}

std::string WaitState::name()
{
	return "Wait state";
}
#pragma endregion WaitState

#pragma region TestState
void TestState::enter(MovingEntity * entity)
{
	entity->setHeading(Vector2D(-50, 20));
	entity->setVelocity(Vector2D(500, 0));
}

void TestState::execute(MovingEntity * entity, double deltaTime)
{
	entity->move(Vector2D(0, 0), deltaTime);
}

void TestState::exit(MovingEntity *)
{

}

std::string TestState::name()
{
	return "Wait state";
}
#pragma endregion TestState

#pragma region ChaseState
void ChaseState::enter(MovingEntity * entity)
{
	entity->setHeading(Vector2D(20, 0));
	entity->setVelocity(Vector2D(500, 500));
}

void ChaseState::execute(MovingEntity * entity, double deltaTime)
{
	
	entity->move(entity->getSteeringBehaviour()->pursuit(entity->getPitch()->getBall()),deltaTime);
}

void ChaseState::exit(MovingEntity *)
{

}

std::string ChaseState::name()
{
	return "chase state";
}
#pragma endregion ChaseState
