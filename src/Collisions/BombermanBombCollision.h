#ifndef _BOMBERMAN_BOMB_COLLISION_H_
#define _BOMBERMAN_BOMB_COLLISION_H_

#include "Collision.h"

class BombermanBombCollision : public Collision{
	
	public:
		BombermanBombCollision(ComponentContext &_context)
		:context(_context){
		}
	
		virtual bool operator()(EntityComponent &bomberman, EntityComponent &bomb){
			// If player just put the bomb
			if(context.render_components.components[bomberman.getId()]->overlapWithLastPosition(*context.render_components.components[bomb.getId()])){
				return true;
			}
				
			return false;
		}
	
	private:
		ComponentContext &context;
};

#endif
