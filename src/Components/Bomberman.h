#ifndef _BOMBERMAN_COMPONENT_H_
#define _BOMBERMAN_COMPONENT_H_

#include "EntityComponent.h"

class Bomberman : public EntityComponent{
	
	public:		
		Bomberman(const EntityId &);
	
		unsigned int getBombs() const;
		void increaseBombs();
		void decreaseBombs();

		unsigned int getBombsScope() const;
		void increaseBombsScope();
		void decreaseBombsScope();	
	
		unsigned int getBombsCapacity() const;
		void increaseBombsCapacity();
		void decreaseBombsCapacity();

		float getSpeed() const;
		void increaseSpeed();
		void decreaseSpeed();
	
	private:
		unsigned int bombs_capacity;
		unsigned int bombs_scope;
		unsigned int bombs;
		float speed;
};

#endif
