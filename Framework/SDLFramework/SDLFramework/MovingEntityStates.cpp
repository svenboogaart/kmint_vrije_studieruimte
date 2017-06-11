#include "MovingEntityStates.h"
#include "PlayerBase.h"
#include "SteeringBehaviors.h"
#include <memory>
#include "SoccerPitch.h"
#include "FieldPlayer.h"

#pragma region ReturnState
void ReturnState::enter(PlayerBase * ball)
{
}

void ReturnState::execute(PlayerBase * entity , double deltaTime)
{
	if (entity->isClosestToBall())
	{
		std::shared_ptr<ChaseState> nextState = std::make_shared<ChaseState>();
		entity->getStateMachine()->changeState(nextState);
	}
	else
	{
		Vector2D target = entity->getTargetPosition();
		entity->move(entity->getSteeringBehaviour()->arrive(target), deltaTime);
		if (entity->getPosition().distanceTo(target) < 5)
		{
			std::shared_ptr<WaitState> nextState = std::make_shared<WaitState>();
			entity->getStateMachine()->changeState(nextState);
		}
	}
	
}

void ReturnState::exit(PlayerBase * ball)
{
}

std::string ReturnState::name()
{
	return "Return state";
}
#pragma endregion ReturnState

#pragma region WaitState
void WaitState::enter(PlayerBase *)
{

}

void WaitState::execute(PlayerBase * entity, double deltaTime)
{
	if (entity->isClosestToBall())
	{
		std::shared_ptr<ChaseState> nextState = std::make_shared<ChaseState>();
		entity->getStateMachine()->changeState(nextState);
	}
}

void WaitState::exit(PlayerBase *)
{

}

std::string WaitState::name()
{
	return "Wait state";
}
#pragma endregion WaitState

#pragma region TestState
void TestState::enter(PlayerBase * entity)
{
	entity->setHeading(Vector2D(-50, 20));
	entity->setVelocity(Vector2D(500, 500));
}

void TestState::execute(PlayerBase * entity, double deltaTime)
{
	entity->move(Vector2D(0, 0), deltaTime);
}

void TestState::exit(PlayerBase *)
{

}

std::string TestState::name()
{
	return "Wait state";
}
#pragma endregion TestState

#pragma region ChaseState
void ChaseState::enter(PlayerBase * entity)
{
	entity->setHeading(Vector2D(20, 0));
	entity->setVelocity(Vector2D(500, 650));
}

void ChaseState::execute(PlayerBase * entity, double deltaTime)
{
	if (entity->m_type != BALL)
	{
		SoccerBall* ball = entity->getPitch()->getBall();
		entity->move(entity->getSteeringBehaviour()->pursuit(ball), deltaTime);
		if (entity->getPosition().distanceTo(ball->getPosition()) < 120)
		{
			//ball->Trap(entity);
			entity->getPitch()->setControl(entity->getTeam()->getColor());
		}
		if(!entity->isClosestToBall())
		{
			std::shared_ptr<ReturnState> nextState = std::make_shared<ReturnState>();
			entity->getStateMachine()->changeState(nextState);
		}
	}
	
}

void ChaseState::exit(PlayerBase *)
{

}

std::string ChaseState::name()
{
	return "chase state";
}
#pragma endregion ChaseState


#pragma region KickState
void KickState::enter(PlayerBase * player)
{
	player->getTeam()->SetControllingPlayer(player);
	if (!player->IsReadyForKick())
	{
		std::shared_ptr<ChaseState> nextState = std::make_shared<ChaseState>();
		player->getStateMachine()->changeState(nextState);
	}
}

void KickState::execute(PlayerBase * player, double deltaTime)
{
	
}

void KickState::exit(PlayerBase *)
{
}

std::string KickState::name()
{
	return std::string();
}
#pragma endregion KickState