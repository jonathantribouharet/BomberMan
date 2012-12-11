#include "MovableComponent.h"

MovableComponent::MovableComponent(const EntityId &id, const Position &_position, std::map<Position::Direction, SDL_Surface *> &_surfaces, Position::Direction _orientation, const double &_speed)
:RenderComponent(id, _position, _surfaces[_orientation]),
speed(_speed),
orientation(_orientation),
surfaces(_surfaces){
}

MovableComponent::~MovableComponent(){
}

float MovableComponent::getSpeed() const{
	return speed;
}

void MovableComponent::setSpeed(const float &_speed){
	speed = _speed;
}

Position::Direction MovableComponent::getOrientation(){
	return orientation;
}

void MovableComponent::setOrientation(Position::Direction _orientation){
	orientation = _orientation;

	if(surfaces.size() > 1){
		surface = surfaces[orientation];
	}
}
