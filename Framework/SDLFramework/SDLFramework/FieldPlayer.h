#pragma once
#include "PlayerBase.h"

class FieldPlayer:public PlayerBase
{
public:
	FieldPlayer(Vector2D initialPosition, SDL_Texture* _m_texture);
};

