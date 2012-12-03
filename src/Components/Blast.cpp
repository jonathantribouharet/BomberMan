#include "Blast.h"

Blast::Blast(const EntityId &id, const EntityId &_bomberman_id, unsigned int _scope)
:EntityComponent(id),
bomberman_id(_bomberman_id),
scope(_scope){
}

Blast::EntityId Blast::getBomberanId() const{
	return bomberman_id;
}

unsigned int Blast::getScope() const{
	return scope;
}
