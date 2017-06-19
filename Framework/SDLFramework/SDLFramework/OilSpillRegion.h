#pragma once
#include "TriggerRegion.h"

class OilSpillRegion : public TriggerRegion
{
public:
	OilSpillRegion(Vector2D position, int width, int height);
	~OilSpillRegion();


	// Inherited via TriggerRegion
	virtual void RunOnEntity(MovingEntity) override;

};

