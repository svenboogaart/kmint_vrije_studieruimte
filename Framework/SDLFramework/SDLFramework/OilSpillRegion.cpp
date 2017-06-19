#include "OilSpillRegion.h"



OilSpillRegion::OilSpillRegion(Vector2D position,  int width, int height):TriggerRegion(position, FWApplication::GetInstance()->LoadTexture("oilspill.png"), width, height)
{
}


OilSpillRegion::~OilSpillRegion()
{
}

void OilSpillRegion::RunOnEntity(MovingEntity)
{
}
