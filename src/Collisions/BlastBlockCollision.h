#ifndef _BLAST_BLOCK_COLLISION_H_
#define _BLAST_BLOCK_COLLISION_H_

#include "Collision.h"

#include "Randomizer.h"

class BlastBlockCollision : public Collision{
	
	public:
		BlastBlockCollision(ComponentContext &_context)
		:context(_context){
		}
		
		virtual bool operator()(EntityComponent &blast, EntityComponent &wall){
			context.removeComponent(blast.getId());
			
			if(context.walls.components[wall.getId()]->isDestructible()){
				context.createBonus(context.render_components.components[wall.getId()]->getPosition(), static_cast<Bonus::BonusType>(Randomizer::getRandomValue(Bonus::RANDOM, Bonus::DECREASE_SPEED)));
				context.removeComponent(wall.getId());
			}

			return false;
		}
	
	private:
		ComponentContext &context;
};

#endif
