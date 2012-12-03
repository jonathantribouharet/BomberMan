#ifndef _EXPLOSE_BOMB_ACTION_H_
#define _EXPLOSE_BOMB_ACTION_H_

#include "Action.h"
#include "EntityComponent.h"
#include "GameContext.h"

class ExploseBombAction : public Action{
	
	public:
		ExploseBombAction(GameContext &, const EntityComponent::EntityId &);
		virtual bool process();
	
	private:
		GameContext &context;
		EntityComponent::EntityId bomb_id;
};

#endif
