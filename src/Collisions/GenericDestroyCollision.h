#ifndef _GENERIC_DESTROY_COLLISION_H_
#define _GENERIC_DESTROY_COLLISION_H_

#include "Collision.h"

class GenericDestroyCollision : public Collision{
	
	public:
		GenericDestroyCollision(ComponentContext &_context)
		:context(_context){
		}
		
		virtual bool operator()(EntityComponent &destoyer, EntityComponent &destroyable){
			context.removeComponent(destoyer.getId());
			context.removeComponent(destroyable.getId());

			return false;
		}
	
	private:
		ComponentContext &context;
};

#endif
