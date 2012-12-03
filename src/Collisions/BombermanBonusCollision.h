#ifndef _BOMBERMAN_BONUS_COLLISION_H_
#define _BOMBERMAN_BONUS_COLLISION_H_

#include "Collision.h"

class BombermanBonusCollision : public Collision{
	
	public:
		BombermanBonusCollision(ComponentContext &_context)
		:context(_context){
		}		
			
		virtual bool operator()(EntityComponent &bomberman, EntityComponent &bonus){
			switch(context.bonuses.components[bonus.getId()]->getType()){
				case Bonus::INCREASE_SPEED:
					context.bombermans.components[bomberman.getId()]->increaseSpeed();
					context.render_components.components[bomberman.getId()]->setSpeed(context.bombermans.components[bomberman.getId()]->getSpeed());
					break;
				case Bonus::DECREASE_SPEED:
					context.bombermans.components[bomberman.getId()]->decreaseSpeed();
					context.render_components.components[bomberman.getId()]->setSpeed(context.bombermans.components[bomberman.getId()]->getSpeed());
					break;
				case Bonus::INCREASE_BOMBS_CAPACITY:
					context.bombermans.components[bomberman.getId()]->increaseBombsCapacity();
					context.bombermans.components[bomberman.getId()]->increaseBombs();
					break;
				case Bonus::DECREASE_BOMBS_CAPACITY:
					context.bombermans.components[bomberman.getId()]->decreaseBombsCapacity();
					break;
				case Bonus::INCREASE_BOMBS_SCOPE:
					context.bombermans.components[bomberman.getId()]->increaseBombsScope();
					break;
				case Bonus::DECREASE_BOMBS_SCOPE:
					context.bombermans.components[bomberman.getId()]->decreaseBombsScope();
					break;
				default:
					break;
			}
			
			context.removeComponent(bonus.getId());
			return true;
		}
		
	private:
		ComponentContext &context;
};

#endif
