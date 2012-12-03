#ifndef _COLLIDER_H_
#define _COLLIDER_H_

#include <map>
#include <string>
#include <typeinfo>

#include "Util.h"
#include "EntityComponent.h"
#include "Collision.h"

class Collider{
	
	public:
		Collider();
		~Collider();
	
		//Return false if collision block the movement
		bool processCollision(EntityComponent &, EntityComponent &);
	
		template<class Component1, class Component2>
		void registerCollision(Collision *collision){
			collisions[std::make_pair(typeid(Component1).name(), typeid(Component2).name())] = collision;
		}
	
	private:	
		DISALLOW_COPY_AND_ASSIGN(Collider)
		
		typedef std::map< std::pair<std::string, std::string>, Collision *> HitMap;
		HitMap collisions;
};

#endif
