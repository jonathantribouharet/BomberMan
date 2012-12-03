#ifndef _KEYBOARD_INPUT_COMPONENT_H_
#define _KEYBOARD_INPUT_COMPONENT_H_

#include "InputComponent.h"

class KeyboardInputComponent : public InputComponent{
	
	public:
		KeyboardInputComponent(const EntityId &, const InputComponent::KeyboardConfig &);
		virtual bool isPlaying(InputAction);
	
	private:
		InputComponent::KeyboardConfig config;
};

#endif
