#ifndef _PANEL_COMPONENT_H_
#define _PANEL_COMPONENT_H_

#include "RenderComponent.h"

class PanelComponent : public RenderComponent{

	public:
		PanelComponent(const EntityId &, int, const EntityId &);
		virtual ~PanelComponent();
		
		EntityId getBombermanId() const;
		void updateValues(unsigned int, unsigned int, unsigned int, float);

	private:
		const int index;
		const EntityId bomberman_id;

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
