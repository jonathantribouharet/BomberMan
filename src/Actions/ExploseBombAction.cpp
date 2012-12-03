#include "ExploseBombAction.h"
#include "CheckScopeBlastAction.h"

using namespace std;

ExploseBombAction::ExploseBombAction(GameContext &_context, const EntityComponent::EntityId & _bomb_id)
:context(_context),
bomb_id(_bomb_id){	
}

bool ExploseBombAction::process(){
	SystemComponent<Bomb>::Components::iterator it = context.componentContext.bombs.components.find(bomb_id);
	
	if(it == context.componentContext.bombs.components.end()){
		return true;	
	}
	
	if(it->second->isExplode()){
		vector<EntityComponent::EntityId> ids = context.componentContext.createBlast(context.componentContext.render_components.components[bomb_id]->getPosition(), it->second->getBombermanId(), it->second->getScope());

		for(unsigned int i = 0; i < ids.size(); ++i){
			context.actionContext.pushAction(new CheckScopeBlastAction(context.componentContext, ids[i]));
		}

		SystemComponent<Bomberman>::Components::iterator it_bomberman = context.componentContext.bombermans.components.find(it->second->getBombermanId());
		if(it_bomberman != context.componentContext.bombermans.components.end()){
			it_bomberman->second->increaseBombs();
		}

		context.componentContext.removeComponent(bomb_id);
	}
	
	return false;
}
