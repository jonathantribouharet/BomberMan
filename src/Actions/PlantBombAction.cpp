#include "PlantBombAction.h"
#include "ExploseBombAction.h"

#define MAP_COMPONENT_SIZE 40
#define BOMBERMAN_WIDTH 20
#define BOMBERMAN_HEIGHT 30

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
	position.setX(((unsigned int)(position.getX() + (BOMBERMAN_WIDTH / 2)) / MAP_COMPONENT_SIZE) * MAP_COMPONENT_SIZE);
	position.setY(((unsigned int)(position.getY() + (BOMBERMAN_HEIGHT / 2)) / MAP_COMPONENT_SIZE) * MAP_COMPONENT_SIZE);
	
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
