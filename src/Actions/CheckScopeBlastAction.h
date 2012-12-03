#ifndef _CHECK_SCOPE_BLAST_ACTION_H_
#define _CHECK_SCOPE_BLAST_ACTION_H_

#include "Action.h"
#include "EntityComponent.h"
#include "ComponentContext.h"

class CheckScopeBlastAction : public Action{

	public:
		CheckScopeBlastAction(ComponentContext &, const EntityComponent::EntityId &);
		virtual bool process();
	
	private:
		ComponentContext &context;
		EntityComponent::EntityId blast_id;	
		Position start_position;
};

#endif
