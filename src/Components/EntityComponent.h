#ifndef _ENTITY_COMPONENT_H_
#define _ENTITY_COMPONENT_H_

#include "Util.h"

class EntityComponent{
	
	public:
		typedef unsigned long EntityId;

		EntityComponent(const EntityId &id)
		:owner(id){
		}
			
		virtual ~EntityComponent(){
		}
			
		EntityId getId() const{
			return owner;
		}
		
	private:
		DISALLOW_COPY_AND_ASSIGN(EntityComponent)
		
		const EntityId owner;		
};

#endif
