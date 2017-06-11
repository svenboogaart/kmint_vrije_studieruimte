#include "FieldPlayer.h"



FieldPlayer::FieldPlayer(Vector2D initialPosition, SDL_Texture* _m_texture, SoccerPitch* pitch, SoccerTeam* team)
	:PlayerBase(initialPosition,pitch, team)
{
	m_texture = _m_texture;
	m_type = EntityType::FIELDPLAYER;
}
