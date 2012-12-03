#include "RenderComponent.h"

#define inrange(x, y, z) ((x >= y) && (x < z))

RenderComponent::RenderComponent(const EntityId &id, const Position &_position, SDL_Surface *_surface, const double &_speed)
:EntityComponent(id),
position(_position),
last_position(_position),
speed(_speed),
orientation(Position::UP){
	surfaces.insert(std::make_pair(orientation, _surface));
}

RenderComponent::RenderComponent(const EntityId &id, const Position &_position, const std::map<Position::Direction, SDL_Surface *> &_surfaces, Position::Direction _orientation, const double &_speed)
:EntityComponent(id),
position(_position),
last_position(_position),
speed(_speed),
orientation(_orientation){
	surfaces = _surfaces;
}

SDL_Surface *RenderComponent::getSurface(){
	return surfaces[orientation];
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

float RenderComponent::getSpeed() const{
	return speed;
}

void RenderComponent::setSpeed(const float &_speed){
	speed = _speed;
}

Position::Direction RenderComponent::getOrientation(){
	return orientation;
}

void RenderComponent::setOrientation(Position::Direction _orientation){
	if(surfaces.size() > 1){
		orientation = _orientation;
	}
}

bool RenderComponent::overlap(RenderComponent &render){	
   bool xo = inrange(position.getX(), render.position.getX(), render.position.getX() + render.surfaces[render.orientation]->w) ||
           inrange(render.position.getX(), position.getX(), position.getX() + surfaces[orientation]->w);
	
   bool yo = inrange(position.getY(), render.position.getY(), render.position.getY() + render.surfaces[render.orientation]->h) ||
           inrange(render.position.getY(), position.getY(), position.getY() + surfaces[orientation]->h);

   return xo && yo;
}

bool RenderComponent::overlapWithLastPosition(RenderComponent &render){		
   bool xo = inrange(last_position.getX(), render.position.getX(), render.position.getX() + render.surfaces[render.orientation]->w) ||
           inrange(render.position.getX(), last_position.getX(), last_position.getX() + surfaces[orientation]->w);
	
   bool yo = inrange(last_position.getY(), render.position.getY(), render.position.getY() + render.surfaces[render.orientation]->h) ||
           inrange(render.position.getY(), last_position.getY(), last_position.getY() + surfaces[orientation]->h);

   return xo && yo;
}
