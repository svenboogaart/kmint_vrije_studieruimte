#include "FieldPlayer.h"



FieldPlayer::FieldPlayer(Vector2D initialPosition, SDL_Texture* _m_texture)
	:PlayerBase(initialPosition)
{
	m_texture = _m_texture;
}
