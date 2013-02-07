#include "PlantBombAction.h"
#include "ExploseBombAction.h"

PlantBombAction::PlantBombAction(GameContext &_context, const EntityComponent::EntityId & _bomberman_id)
:context(_context),
bomberman_id(_bomberman_id){	
}

bool PlantBombAction::process(){
	SystemComponent<RenderComponent>::Components::iterator it_bomberman = context.componentContext.render_components.components.find(bomberman_id);
	
	if(it_bomberman == context.componentContext.render_components.components.end()){
		return true;
	}

	if(context.componentContext.bombermans.components[it_bomberman->first]->getBombs() == 0){
		return true;
	}

	RenderComponent *render = it_bomberman->second;
	
	Position position = render->getPosition();

	//Place bomb in center of square
	position.setX(((unsigned int)(position.getX() + (context.componentContext.mapContext.bombermanWidth / 2)) / context.componentContext.mapContext.cellWidth) * context.componentContext.mapContext.cellWidth);
	position.setY(((unsigned int)(position.getY() + (context.componentContext.mapContext.bombermanHeight / 2)) / context.componentContext.mapContext.cellHeight) * context.componentContext.mapContext.cellHeight);
	
	//Avoid place 2 bombs in same time
	for(SystemComponent<Bomb>::Components::const_iterator it_bomb = context.componentContext.bombs.components.begin();
		it_bomb != context.componentContext.bombs.components.end();
		++it_bomb){

		if(context.componentContext.render_components.components[it_bomb->first]->getPosition() == position){
			return true;
		}
	}

	EntityComponent::EntityId bomb_id = context.componentContext.createBomb(position, it_bomberman->first);
	context.actionContext.pushAction(new ExploseBombAction(context, bomb_id));
	context.componentContext.bombermans.components[it_bomberman->first]->decreaseBombs();
	context.componentContext.updatePanel(it_bomberman->first);

	return true;
}
