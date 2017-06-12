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
	Vector2D m_receivePosition;
	double m_kicked = 0;
public:
	SoccerTeam * getTeam();
	PlayerBase(Vector2D initialPosition, SoccerPitch* pitch, SoccerTeam* team);
	bool CanPassForward(PlayerBase * receiver, PlayerBase * target, double  power);
	bool CanPassBackward(PlayerBase * receiver, PlayerBase * target, double  power);
	std::shared_ptr<StateMachine<PlayerBase>> getStateMachine();
	void SetState(std::shared_ptr<State<PlayerBase>>);
	Vector2D getReceivePosition();
	bool WithingShootingRange();
	bool AtTarget();
	bool IsReadyForKick();
	void kicked();
	void setAttackingPosition();
	void Update(double deltaTime);
	void setDefendingPosition();
	void ReceiveBall(Vector2D position);
};

