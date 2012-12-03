#ifndef _BOMB_COMPONENT_H_
#define _BOMB_COMPONENT_H_

#include "EntityComponent.h"

#include "SDL.h"

class Bomb : public EntityComponent{
	
	public:
		Bomb(const EntityId &, const EntityId &, unsigned int);
		
		EntityId getBombermanId() const;
		unsigned int getScope() const;
		
		bool isExplode() const;
		void setExploded();
	
	private:
		const EntityId bomberman_id;
		const unsigned int scope;
		
		bool manual_explode;
		Uint32 created_at;
};

#endif
