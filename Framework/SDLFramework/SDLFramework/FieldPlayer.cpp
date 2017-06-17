#include "FieldPlayer.h"
#include "SoccerTeam.h"


FieldPlayer::FieldPlayer(Vector2D initialPosition, SDL_Texture* _m_texture, SoccerPitch* pitch, SoccerTeam* team)
	:PlayerBase(initialPosition,pitch, team)
{
	m_position = initialPosition;
	m_texture = _m_texture;
	m_type = EntityType::FIELDPLAYER;
	if (team->getColor() == TEAMCOLOR::RED)
	{
		m_attackPosition = initialPosition - Vector2D(200, 0);
	}
	else {
		m_attackPosition = initialPosition + Vector2D(200, 0);
	}

	m_targetPosition = initialPosition;
}



