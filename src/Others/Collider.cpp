#include "Collider.h"

#include <typeinfo>

using namespace std;

Collider::Collider(){
}

Collider::~Collider(){
	for(HitMap::iterator it = collisions.begin(); it != collisions.end(); ++it){
		delete it->second;
		it->second = NULL;
	}
}

bool Collider::processCollision(EntityComponent &object1, EntityComponent &object2){
	HitMap::const_iterator mapEntry = collisions.find(make_pair(typeid(object1).name(), typeid(object2).name()));
	
	if(mapEntry == collisions.end()){
		return true;
	}
	
	return (*mapEntry->second)(object1, object2);
}
