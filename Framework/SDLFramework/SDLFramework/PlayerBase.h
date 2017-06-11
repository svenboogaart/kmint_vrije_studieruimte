#pragma once
#include "MovingEntity.h"
#include "Vector2D.h"
class SoccerTeam;

class PlayerBase :public MovingEntity
{
private:
	SoccerTeam * m_team;
	std::shared_ptr<StateMachine<PlayerBase>> m_stateMachine;
protected:
	Vector2D m_attackPosition;

public:
	SoccerTeam * getTeam();
	PlayerBase(Vector2D initialPosition, SoccerPitch* pitch, SoccerTeam* team);
	bool CanPassForward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool CanPassBackward(PlayerBase * receiver, PlayerBase * target, double  power);

	std::shared_ptr<StateMachine<PlayerBase>> getStateMachine();
	void SetState(std::shared_ptr<State<PlayerBase>>);
	bool WithingShootingRange();
	bool AtTarget();
	bool IsReadyForKick();
	void setAttackingPosition();
	void Update(double deltaTime);
	void setDefendingPosition();
};

