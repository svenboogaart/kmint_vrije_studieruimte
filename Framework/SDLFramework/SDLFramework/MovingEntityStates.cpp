#include "MovingEntityStates.h"
#include "MovingEntity.h"
#include "SteeringBehaviors.h"
#include <memory>
#include "SoccerPitch.h"

#pragma region ReturnState
void ReturnState::enter(MovingEntity * ball)
{
}

void ReturnState::execute(MovingEntity * entity , double deltaTime)
{
	if (entity->isClosestToBall())
	{
		std::shared_ptr<ChaseState> nextState = std::make_shared<ChaseState>();
		entity->getStateMachine()->changeState(nextState);
	}
	else
	{
		Vector2D target = entity->GetStartPosition();
		entity->move(entity->getSteeringBehaviour()->arrive(target), deltaTime);
		if (entity->getPosition().distanceTo(target) < 5)
		{
			std::shared_ptr<WaitState> nextState = std::make_shared<WaitState>();
			entity->getStateMachine()->changeState(nextState);
		}
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

void WaitState::execute(MovingEntity * entity, double deltaTime)
{
	if (entity->isClosestToBall())
	{
		std::shared_ptr<ChaseState> nextState = std::make_shared<ChaseState>();
		entity->getStateMachine()->changeState(nextState);
	}
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
	entity->setVelocity(Vector2D(500, 500));
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
	entity->setVelocity(Vector2D(500, 650));
}

void ChaseState::execute(MovingEntity * entity, double deltaTime)
{
	if (entity->m_type != BALL)
	{
		entity->move(entity->getSteeringBehaviour()->pursuit(entity->getPitch()->getBall()), deltaTime);
		
		if(!entity->isClosestToBall())
		{
			std::shared_ptr<ReturnState> nextState = std::make_shared<ReturnState>();
			entity->getStateMachine()->changeState(nextState);
		}
	}
	
}

void ChaseState::exit(MovingEntity *)
{

}

std::string ChaseState::name()
{
	return "chase state";
}
#pragma endregion ChaseState
