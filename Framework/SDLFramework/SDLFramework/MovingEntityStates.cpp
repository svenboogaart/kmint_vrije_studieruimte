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
}

void ChaseState::execute(PlayerBase * entity, double deltaTime)
{
	if (entity->m_type != BALL)
	{
		SoccerBall* ball = entity->getPitch()->getBall();
		entity->move(entity->getSteeringBehaviour()->pursuit(ball), deltaTime);
		if (entity->getPosition().distanceTo(ball->getPosition()) < 24*24)
		{
			//ball->Trap(entity);
			entity->getPitch()->setControl(entity->getTeam()->getColor());
		}
		if (entity->getPosition().distanceTo(ball->getPosition()) < 20*20 && entity->CanKick())
		{
			std::shared_ptr<KickState> nextState = std::make_shared<KickState>();
			entity->getStateMachine()->changeState(nextState);
		}
		if(!entity->isClosestToBall())
		{
			std::shared_ptr<ReturnState> nextState = std::make_shared<ReturnState>();
			entity->getStateMachine()->changeState(nextState);
		}
		else if (entity->getPosition().distanceTo(ball->getPosition()) < 20 * 20 && !entity->CanKick())
		{
			
			Vector2D desiredShot = entity->getPosition();
		
			Vector2D difference = desiredShot - entity->getPitch()->getBall()->getPosition();
			entity->getPitch()->getBall()->Kick(difference, 1);
		}
		else {
			//std::cout << "the end "<< entity->getPosition().distanceTo(ball->getPosition())<<"\n " ;
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
	/*if (player->getTeam()->getReceiver() != player && player->getTeam()->getReceiver() != NULL && player->getTeam()->getReceiver() != nullptr)
	{
		player->getTeam()->SetReceivingPlayer(nullptr);
		player->getStateMachine()->changeState(std::make_shared<ChaseState>());
		return;
	}
	else
	{
		std::cout << "already a receiver \n";
	}*/
	Vector2D desiredShot;
	if (player->getPosition().distanceTo(player->getPitch()->getBall()->getPosition()) > 20*20)
	{
		player->getStateMachine()->changeState(std::make_shared<ChaseState>());
		return;
	}
	if (player->getTeam()->closestToGoal() != player)
	{
		player->getTeam()->closestToGoal()->ReceiveBall(player->getPosition());
		desiredShot = player->getTeam()->closestToGoal()->getPosition();
	}
	else if (player->getTeam()->getColor() == TEAMCOLOR::RED)
	{
		desiredShot = Vector2D(0, 300);
	}
	else
	{
		desiredShot = Vector2D(1000, 300);
	}
	//player->getTeam()->SetReceivingPlayer(nullptr);
	Vector2D difference = desiredShot - player->getPitch()->getBall()->getPosition();
	player->getPitch()->getBall()->Kick(difference, 1);
}

void KickState::exit(PlayerBase *)
{
}

std::string KickState::name()
{
	return std::string();
}
#pragma endregion KickState

void ReceiveState::enter(PlayerBase * player)
{
}

void ReceiveState::execute(PlayerBase * player, double deltaTime)
{
	if (player->isClosestToBall())
	{
		std::shared_ptr<ChaseState> nextState = std::make_shared<ChaseState>();
		player->getStateMachine()->changeState(nextState);
		return;
	}
	if (player->getPosition().distanceTo(player->getPitch()->getBall()->getPosition()) < 10 * 10 && player->CanKick())
	{
		std::shared_ptr<KickState> nextState = std::make_shared<KickState>();
		player->getStateMachine()->changeState(nextState);
		return;
	}
	else if (player->getPosition().distanceTo(player->getPitch()->getBall()->getPosition()) < 10 * 10)
	{
		std::shared_ptr<ChaseState> nextState = std::make_shared<ChaseState>();
		player->getStateMachine()->changeState(nextState);
		return;
	}
	else if (!player->getPosition().distanceTo(player->getReceivePosition()) < 5 * 5)
	{
		player->move(player->getSteeringBehaviour()->arrive(player->getReceivePosition()), deltaTime);
	}
	else {
		player->setVelocity(Vector2D(0, 0));
	}
}

void ReceiveState::exit(PlayerBase *)
{
}

std::string ReceiveState::name()
{
	return std::string();
}
