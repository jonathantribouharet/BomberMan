#include "LinearInputComponent.h"

LinearInputComponent::LinearInputComponent(const EntityId &id, InputAction _action)
:InputComponent(id),
action(_action){
}

bool LinearInputComponent::isPlaying(InputAction _action){
	if(action == _action){
		return true;
	}
	
	return false;
}
