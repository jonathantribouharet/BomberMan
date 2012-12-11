#ifndef _MOVABLE_COMPONENT_H_
#define _MOVABLE_COMPONENT_H_

#include "RenderComponent.h"

class MovableComponent : public RenderComponent{

	public:
		MovableComponent(const EntityId &, const Position &, std::map<Position::Direction, SDL_Surface *> &, Position::Direction = Position::UP, const double & = 0);
		virtual ~MovableComponent();

		float getSpeed() const;
		void setSpeed(const float &);
	
		Position::Direction getOrientation();
		void setOrientation(Position::Direction);

	private:
		float speed;

		Position::Direction orientation;
		std::map<Position::Direction, SDL_Surface *> surfaces;
};

#endif
