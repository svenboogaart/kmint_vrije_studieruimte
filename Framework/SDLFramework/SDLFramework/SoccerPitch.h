#pragma once
#include "FWApplication.h"
#include "SoccerBall.h"
#include "SoccerTeam.h"
#include "SoccerPitch.h"
#include <vector>
#include "TriggerRegion.h"
#include "OilManager.h"

enum GOAL{ LEFT, RIGHT };

class SoccerPitch
{

private:
	SDL_Texture* m_texture;
	SoccerBall * m_ball;
	std::vector<std::shared_ptr<TriggerRegion>> m_triggers;
	SoccerTeam * m_redTeam;
	SoccerTeam * m_blueTeam;
	std::shared_ptr<OilManager> m_oilManager;
	void PrintScore();
public:
	bool m_keeperHasBall = false;
	SoccerTeam * getTeam(TEAMCOLOR color);
	void setControl(TEAMCOLOR color);
	SoccerPitch();
	~SoccerPitch();
	void Update(double deltaTime);
	bool EveryBodyIsHome();
	void Render();
	SoccerBall * getBall();
	void goalScored(GOAL position);
	void startRound();
	void CheckTriggerRegions();
	void DropOil(Vector2D position);
};

