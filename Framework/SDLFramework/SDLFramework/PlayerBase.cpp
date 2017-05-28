#include "PlayerBase.h"



PlayerBase::PlayerBase(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate)
	:MovingEntity(x, y, width, height, mass, maxSpeed, maxForce, maxTurnRate)
{

}


bool PlayerBase::CanPassForward(PlayerBase * receiver, PlayerBase * target, double power)
{
	return false;
}

bool PlayerBase::CanPassBackward(PlayerBase * receiver, PlayerBase * target, double power)
{
	return false;
}

bool PlayerBase::WithingShootingRange()
{
	return false;
}

bool PlayerBase::AtTarget()
{
	return false;
}
