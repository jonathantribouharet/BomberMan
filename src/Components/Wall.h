#ifndef _WALL_COMPONENT_H_
#define _WALL_COMPONENT_H_

#include "EntityComponent.h"

class Wall : public EntityComponent{
	
	public:
		Wall(const EntityId &, bool);		
		bool isDestructible() const;
	
	private:
		bool is_destructible;
};

#endif
