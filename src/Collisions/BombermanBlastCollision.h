#ifndef _BOMBERMAN_BLAST_COLLISION_H_
#define _BOMBERMAN_BLAST_COLLISION_H_

#include "Collision.h"

class BombermanBlastCollision : public Collision{
	
	public:
		BombermanBlastCollision(ComponentContext &_context)
		:context(_context){
		}
	
		virtual bool operator()(EntityComponent &bomberman, EntityComponent &blast){
			context.removeComponent(bomberman.getId());
			context.removeComponent(blast.getId());
			
			return false;
		}
	
	private:
		ComponentContext &context;
};

#endif
