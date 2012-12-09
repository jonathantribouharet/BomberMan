#ifndef _BOMBERMAN_BONUS_COLLISION_H_
#define _BOMBERMAN_BONUS_COLLISION_H_

#include "Collision.h"

#include "PlaySoundAction.h"

class BombermanBonusCollision : public Collision{
	
	public:
		BombermanBonusCollision(GameContext &_context)
		:context(_context){
		}		
			
		virtual bool operator()(EntityComponent &bomberman, EntityComponent &bonus){
			switch(context.componentContext.bonuses.components[bonus.getId()]->getType()){
				case Bonus::INCREASE_SPEED:
					context.componentContext.bombermans.components[bomberman.getId()]->increaseSpeed();
					context.componentContext.render_components.components[bomberman.getId()]->setSpeed(context.componentContext.bombermans.components[bomberman.getId()]->getSpeed());
					break;
				case Bonus::DECREASE_SPEED:
					context.componentContext.bombermans.components[bomberman.getId()]->decreaseSpeed();
					context.componentContext.render_components.components[bomberman.getId()]->setSpeed(context.componentContext.bombermans.components[bomberman.getId()]->getSpeed());
					break;
				case Bonus::INCREASE_BOMBS_CAPACITY:
					context.componentContext.bombermans.components[bomberman.getId()]->increaseBombsCapacity();
					context.componentContext.bombermans.components[bomberman.getId()]->increaseBombs();
					break;
				case Bonus::DECREASE_BOMBS_CAPACITY:
					context.componentContext.bombermans.components[bomberman.getId()]->decreaseBombsCapacity();
					break;
				case Bonus::INCREASE_BOMBS_SCOPE:
					context.componentContext.bombermans.components[bomberman.getId()]->increaseBombsScope();
					break;
				case Bonus::DECREASE_BOMBS_SCOPE:
					context.componentContext.bombermans.components[bomberman.getId()]->decreaseBombsScope();
					break;
				default:
					break;
			}
			
			context.actionContext.pushAction(new PlaySoundAction(AssetLoader::BONUS));
			context.componentContext.updatePanel(bomberman.getId());
			context.componentContext.removeComponent(bonus.getId());
			return true;
		}
		
	private:
		GameContext &context;
};

#endif
