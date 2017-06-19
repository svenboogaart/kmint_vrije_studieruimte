#pragma once
#include "Vector2D.h"
#include "MovingEntity.h"
class TriggerRegion
{
private:
	SDL_Texture* m_texture;
	Vector2D m_position;
	int m_width, m_height;
public:
	TriggerRegion(Vector2D position, SDL_Texture* texture,int width, int height);
	~TriggerRegion();
	bool isTouching(Vector2D position, double radius);
	void Render();
	virtual void RunOnEntity(MovingEntity) = 0;
	void ChangePosition(Vector2D);

};

