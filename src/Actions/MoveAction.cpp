#include "MoveAction.h"

#include <iostream>
using namespace std;

MoveAction::MoveAction(ComponentContext &_context, const EntityComponent::EntityId & _entityId, Position::Direction _direction)
:context(_context),
entityId(_entityId),
direction(_direction){	
}

bool MoveAction::process(){
	SystemComponent<RenderComponent>::Components::iterator it = context.render_components.components.find(entityId);
	
	if(it == context.render_components.components.end()){
		return true;
	}
		
	RenderComponent *render = it->second;
	
	render->setOrientation(direction);
	render->getPosition().move(direction, render->getSpeed() / context.getSpeed());

	//Need to know if it and / or it_render are removed in a collision and update iterator

	for(SystemComponent<RenderComponent>::Components::iterator it_render = context.collisionables.components.begin();
		it_render != context.collisionables.components.end();
		++it_render){	

		//Hack 1st part
		SystemComponent<RenderComponent>::Components::iterator it_render_next = ++it_render;
		--it_render;

		if(it->second != it_render->second &&
			render->overlap(*context.render_components.components[it_render->first]) &&
			!context.collider.processCollision(*context.components.components[it->first], *context.components.components[it_render->first])){

			if(!context.componentExist(entityId)){
				return true;
			}

			render->getPosition() = render->getLastPosition();

			return true;
		}

		if(!context.componentExist(entityId)){
			return true;
		}

		//Hack 2nd part
		if(!context.componentExist(it_render->first)){
			it_render = it_render_next;
			if(it_render != context.collisionables.components.begin()){
				--it_render;
			}
		}
	}	
	
	render->getLastPosition() = render->getPosition();
	
	return true;
}
