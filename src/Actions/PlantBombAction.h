#ifndef _PLANT_BOMB_ACTION_H_
#define _PLANT_BOMB_ACTION_H_

#include "Action.h"
#include "EntityComponent.h"
#include "GameContext.h"

class PlantBombAction : public Action{
	
	public:
		PlantBombAction(GameContext &, const EntityComponent::EntityId &);
		virtual bool process();
	
	private:
		GameContext &context;
		EntityComponent::EntityId bomberman_id;
};

#endif
