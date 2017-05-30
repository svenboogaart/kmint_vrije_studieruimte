#include "BallStates.h"
#include "MovingEntity.h"
#include "SteeringBehaviors.h"
#include <memory>

void ReturnState::enter(MovingEntity * ball)
{
}

void ReturnState::execute(MovingEntity * ball , double deltaTime)
{
	Vector2D target = ball->GetStartPosition();
	ball->move(ball->getSteeringBehaviour()->seek(target),deltaTime);
	if (ball->getPosition().distanceTo(target) < 10)
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
