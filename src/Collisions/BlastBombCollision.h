#ifndef _BLAST_BOMB_COLLISION_H_
#define _BLAST_BOMB_COLLISION_H_

#include "Collision.h"

class BlastBombCollision : public Collision{
	
	public:
		BlastBombCollision(ComponentContext &_context)
		:context(_context){
		}
		
		virtual bool operator()(EntityComponent &blast, EntityComponent &bomb){
			context.removeComponent(blast.getId());
			context.bombs.components[bomb.getId()]->setExploded();
			
			return false;
		}
	
	private:
		ComponentContext &context;
};

#endif
