#include "RenderComponent.h"

#define inrange(x, y, z) ((x >= y) && (x < z))

RenderComponent::RenderComponent(const EntityId &id, const Position &_position, SDL_Surface *_surface)
:EntityComponent(id),
surface(_surface),
position(_position),
last_position(_position){
}

RenderComponent::~RenderComponent(){
}

SDL_Surface *RenderComponent::getSurface(){
	return surface;
}

Position &RenderComponent::getPosition(){
	return position;
}

Position &RenderComponent::getLastPosition(){
	return last_position;
}

SDL_Rect *RenderComponent::getScreenPosition(){
	sdl_position.x = position.getX();
	sdl_position.y = position.getY();
	return &sdl_position;
}

bool RenderComponent::overlap(RenderComponent &render){	
   bool xo = inrange(position.getX(), render.position.getX(), render.position.getX() + render.getSurface()->w) ||
           inrange(render.position.getX(), position.getX(), position.getX() + getSurface()->w);
	
   bool yo = inrange(position.getY(), render.position.getY(), render.position.getY() + render.getSurface()->h) ||
           inrange(render.position.getY(), position.getY(), position.getY() + getSurface()->h);

   return xo && yo;
}

bool RenderComponent::overlapWithLastPosition(RenderComponent &render){		
   bool xo = inrange(last_position.getX(), render.position.getX(), render.position.getX() + render.getSurface()->w) ||
           inrange(render.position.getX(), last_position.getX(), last_position.getX() + getSurface()->w);
	
   bool yo = inrange(last_position.getY(), render.position.getY(), render.position.getY() + render.getSurface()->h) ||
           inrange(render.position.getY(), last_position.getY(), last_position.getY() + getSurface()->h);

   return xo && yo;
}
