#include "KeyboardInputComponent.h"

#include "SDL.h"

static Uint8 *keysstate = SDL_GetKeyState(NULL);

KeyboardInputComponent::KeyboardInputComponent(const EntityId &id, const InputComponent::KeyboardConfig &_config)
:InputComponent(id),
config(_config){
}

bool KeyboardInputComponent::isPlaying(InputAction action){
	// SDL_PumpEvents(); //call by SDL_PollEvent
	
	if(keysstate[config[action]]){
		return true;
	}
	
	return false;
}
