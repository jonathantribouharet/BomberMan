#ifndef _INPUT_COMPONENT_H_
#define _INPUT_COMPONENT_H_

#include "EntityComponent.h"

#include <map>

class InputComponent : public EntityComponent{

	public:
		enum InputAction {GO_UP, GO_DOWN, GO_LEFT, GO_RIGHT, PLANT_BOMB};
		typedef std::map<InputAction, int> KeyboardConfig;
		
		InputComponent(const EntityId &id):EntityComponent(id){};
		virtual bool isPlaying(InputAction) = 0;
};

#endif
