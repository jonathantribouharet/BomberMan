#include "GameEngine.h"
#include "SDL.h"

#include "GenericBlockCollision.h"
#include "GenericDestroyCollision.h"
#include "BlastBlockCollision.h"
#include "BlastBombCollision.h"
#include "BombermanBlastCollision.h"
#include "BombermanBombCollision.h"
#include "BombermanBonusCollision.h"

GameEngine::GameEngine(GameContext &context)
:Engine(context){
	context.componentContext.collider.registerCollision<Bomberman, Wall>(new GenericBlockCollision());
	context.componentContext.collider.registerCollision<Bomberman, Bomb>(new BombermanBombCollision(context.componentContext));
	context.componentContext.collider.registerCollision<Bomberman, Blast>(new BombermanBlastCollision(context.componentContext));
	context.componentContext.collider.registerCollision<Bomberman, Bonus>(new BombermanBonusCollision(context));

	context.componentContext.collider.registerCollision<Blast, Wall>(new BlastBlockCollision(context.componentContext));
	context.componentContext.collider.registerCollision<Blast, Bomb>(new BlastBombCollision(context.componentContext));
	context.componentContext.collider.registerCollision<Blast, Bomberman>(new BombermanBlastCollision(context.componentContext));
	context.componentContext.collider.registerCollision<Blast, Bonus>(new GenericDestroyCollision(context.componentContext));
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
