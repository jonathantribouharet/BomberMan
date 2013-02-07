#include "CheckScopeBlastAction.h"
#include <cmath>

CheckScopeBlastAction::CheckScopeBlastAction(ComponentContext &_context, const EntityComponent::EntityId & _blast_id)
:context(_context),
blast_id(_blast_id){	
	start_position = context.render_components.components[blast_id]->getPosition();
}

bool CheckScopeBlastAction::process(){
	SystemComponent<RenderComponent>::Components::iterator it = context.render_components.components.find(blast_id);
	
	if(it == context.render_components.components.end()){
		return true;	
	}

	unsigned int scope = context.blasts.components[blast_id]->getScope();
	Position current_position = context.render_components.components[blast_id]->getPosition();

	if(fabs(start_position.getX() - current_position.getX()) >= (scope * context.mapContext.cellWidth) || fabs(start_position.getY() - current_position.getY()) >= (scope * context.mapContext.cellHeight)){
		context.removeComponent(blast_id);
		return true;
	}

	return false;
}
