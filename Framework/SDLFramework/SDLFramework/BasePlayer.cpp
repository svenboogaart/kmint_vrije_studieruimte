#include "BasePlayer.h"
#include <SDL.h>
#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "FWApplication.h"

BasePlayer::BasePlayer(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate)
	:MovingEntity(x,  y,  width,  height,  mass,  maxSpeed,  maxForce,  maxTurnRate)
{
}