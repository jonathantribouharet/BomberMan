#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "EntityComponent.h"

class Collision{
	
	public:
		virtual ~Collision(){}
		virtual bool operator()(EntityComponent &, EntityComponent &) = 0; //Return false if collision block the movement
};

#endif
