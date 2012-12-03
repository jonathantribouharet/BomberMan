#ifndef _PANEL_COMPONENT_H_
#define _PANEL_COMPONENT_H_

#include "SDL.h"

#include "EntityComponent.h"
#include "Position.h"

class PanelComponent : public EntityComponent{

	public:
		PanelComponent(const EntityId &, int);
		virtual ~PanelComponent();

		SDL_Surface *getSurface();
		Position &getPosition();
		SDL_Rect *getScreenPosition();
	
		void updateValues(unsigned int, unsigned int, unsigned int, float);

	private:
		const int index;

		Position position;
		SDL_Rect sdl_position;

		SDL_Surface *surface;

		SDL_Surface *surface_background;
		SDL_Surface *surface_userame;

		SDL_Surface *surface_bombs;
		SDL_Surface *surface_capacity;
		SDL_Surface *surface_scope;
		SDL_Surface *surface_speed;

		void clearSurfaces();
		void updateSurface(SDL_Surface *, int, int);
};

#endif
