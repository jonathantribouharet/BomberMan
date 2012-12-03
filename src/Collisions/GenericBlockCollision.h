#ifndef _GENERIC_BLOCK_COLLISION_H_
#define _GENERIC_BLOCK_COLLISION_H_

#include "Collision.h"

class GenericBlockCollision : public Collision{
	
	public:
		virtual bool operator()(EntityComponent &, EntityComponent &){return false;}
};

#endif
