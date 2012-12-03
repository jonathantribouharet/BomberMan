#include "InputEngine.h"
#include "MoveAction.h"
#include "PlantBombAction.h"

InputEngine::InputEngine(GameContext &context)
:Engine(context){
}

void InputEngine::process(){
	for(SystemComponent<InputComponent>::Components::const_iterator it = context.componentContext.input_components.components.begin();
		it != context.componentContext.input_components.components.end();
		++it){

		if(it->second->isPlaying(InputComponent::GO_UP)){
			context.actionContext.pushAction(new MoveAction(context.componentContext, it->first, Position::UP));
		}
		if(it->second->isPlaying(InputComponent::GO_DOWN)){
			context.actionContext.pushAction(new MoveAction(context.componentContext, it->first, Position::DOWN));
		}
		if(it->second->isPlaying(InputComponent::GO_LEFT)){
			context.actionContext.pushAction(new MoveAction(context.componentContext, it->first, Position::LEFT));
		}
		if(it->second->isPlaying(InputComponent::GO_RIGHT)){
			context.actionContext.pushAction(new MoveAction(context.componentContext, it->first, Position::RIGHT));
		}
		if(it->second->isPlaying(InputComponent::PLANT_BOMB)){
			context.actionContext.pushAction(new PlantBombAction(context, it->first));
		}
	}
}
