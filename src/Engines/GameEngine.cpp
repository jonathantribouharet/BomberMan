#include "GameEngine.h"
#include "SDL.h"

GameEngine::GameEngine(GameContext &context)
:Engine(context){
}

void GameEngine::process(){
	SDL_Event event;
	if(SDL_PollEvent(&event) == 1 && event.type == SDL_QUIT){
		context.setRunning(false);
		return;
	}

	while(context.actionContext.haveActions()){
		Action *action = context.actionContext.popAction();
		
		if(action->process()){
			delete action;
		}
		else{
			context.actionContext.pushAction(action);
		}
	}
	
	context.actionContext.switchActionsQueue();

	if(context.componentContext.bombermans.components.size() == 1){
		context.setRunning(false);
	}
}
