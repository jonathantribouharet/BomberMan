#ifndef _RENDER_COMPONENT_H_
#define _RENDER_COMPONENT_H_

#include <map>
#include "SDL.h"

#include "EntityComponent.h"
#include "Position.h"

class RenderComponent : public EntityComponent{

	public:
		RenderComponent(const EntityId &, const Position &, SDL_Surface *);
		virtual ~RenderComponent();

		virtual SDL_Surface *getSurface();
		Position &getPosition();
		Position &getLastPosition();
		SDL_Rect *getScreenPosition();
	
		bool overlap(RenderComponent &);
		bool overlapWithLastPosition(RenderComponent &);

	protected:
		SDL_Surface *surface;

	private:
		Position position;
		Position last_position;
		SDL_Rect sdl_position;
};

#endif
