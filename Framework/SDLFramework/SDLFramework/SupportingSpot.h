#pragma once
#include "Vector2D.h"
class SupportingSpot
{
public:
	Vector2D m_vPos;
	double m_dScore;
	SupportingSpot(Vector2D pos, double val);
	~SupportingSpot();

};

