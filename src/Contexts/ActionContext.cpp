#include "ActionContext.h"

ActionContext::ActionContext(){
	actions_queue_in_use = false;
}

void ActionContext::pushAction(Action *action){
	if(actions_queue_in_use){
		next_actions.push(action);
	}else{
		current_actions.push(action);
	}
}

//Suppose call after have check if haveActions
Action *ActionContext::popAction(){
	actions_queue_in_use = true;
	
	Action *action = current_actions.front();
	current_actions.pop();

	return action;
}

bool ActionContext::haveActions() const{
	return !current_actions.empty();
}

//Suppose call after remove all actions in current_actions
void ActionContext::switchActionsQueue(){
	current_actions = next_actions;
	
	while(!next_actions.empty()){
		next_actions.pop();
	}

	actions_queue_in_use = false;
}
