#ifndef _SYSTEM_COMPONENT_H_
#define _SYSTEM_COMPONENT_H_

#include "EntityComponent.h"

#include <map>

template<class C>
class SystemComponent{
	
	public:
		typedef std::map<EntityComponent::EntityId, C *> Components;
		Components components;
};

#endif
