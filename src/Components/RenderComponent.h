#ifndef _RENDER_COMPONENT_H_
#define _RENDER_COMPONENT_H_

#include <map>
#include "SDL.h"

#include "EntityComponent.h"
#include "Position.h"

class RenderComponent : public EntityComponent{

	public:
		RenderComponent(const EntityId &, const Position &, SDL_Surface *, const double & = 0);
		RenderComponent(const EntityId &, const Position &, const std::map<Position::Direction, SDL_Surface *> &, Position::Direction = Position::UP, const double & = 0);

		SDL_Surface *getSurface();
		Position &getPosition();
		Position &getLastPosition();
		SDL_Rect *getScreenPosition();
	
		float getSpeed() const;
		void setSpeed(const float &);
	
		Position::Direction getOrientation();
		void setOrientation(Position::Direction);
	
		bool overlap(RenderComponent &);
		bool overlapWithLastPosition(RenderComponent &);

	private:
		Position position;
		Position last_position;
		SDL_Rect sdl_position;

		float speed;

		std::map<Position::Direction, SDL_Surface *> surfaces;
		Position::Direction orientation;
};

#endif
