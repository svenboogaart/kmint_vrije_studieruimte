#include "OilManager.h"
#include "DropOil.h"


OilManager::OilManager(SoccerPitch * pitch):MovingEntity(0,0,50,50,1,200,300,900, pitch)
{

	m_texture = FWApplication::GetInstance()->LoadTexture("ufo.png");
	m_goal = std::make_shared<DropOil>(this);
	m_position = Vector2D(0, 0);
	m_goal->Activiate(this);
}


OilManager::~OilManager()
{
}

void OilManager::Update(double DeltaTime)
{
	if (!m_goal->isStarted())
	{
		m_goal->Activiate(this);
	}
	m_goal->Process(DeltaTime);
}
