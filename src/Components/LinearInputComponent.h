#ifndef _LINEAR_INPUT_COMPONENT_H_
#define _LINEAR_INPUT_COMPONENT_H_

#include "InputComponent.h"

class LinearInputComponent : public InputComponent{
	
	public:
		LinearInputComponent(const EntityId &, InputAction);
		virtual bool isPlaying(InputAction);
	
	private:
		InputAction action;
};

#endif
