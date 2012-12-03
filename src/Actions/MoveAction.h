#ifndef _MOVE_ACTION_H_
#define _MOVE_ACTION_H_

#include "Action.h"
#include "EntityComponent.h"
#include "Position.h"
#include "ComponentContext.h"

class MoveAction : public Action{
	
	public:
		MoveAction(ComponentContext &, const EntityComponent::EntityId &, Position::Direction);
		virtual bool process();
	
	private:
		ComponentContext &context;
		EntityComponent::EntityId entityId;
		Position::Direction direction;
};

#endif
