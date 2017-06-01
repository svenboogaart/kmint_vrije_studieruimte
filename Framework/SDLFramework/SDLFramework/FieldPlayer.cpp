#include "FieldPlayer.h"



FieldPlayer::FieldPlayer(Vector2D initialPosition, SDL_Texture* _m_texture, SoccerPitch* pitch)
	:PlayerBase(initialPosition,pitch)
{
	m_texture = _m_texture;
}
