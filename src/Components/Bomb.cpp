#include "Bomb.h"

Bomb::Bomb(const EntityId &id, const EntityId &_bomberman_id, unsigned int _scope)
:EntityComponent(id),
bomberman_id(_bomberman_id),
scope(_scope),
manual_explode(false),
created_at(SDL_GetTicks()){
}

EntityComponent::EntityId Bomb::getBombermanId() const{
	return bomberman_id;
}

unsigned int Bomb::getScope() const{
	return scope;
}

bool Bomb::isExplode() const{
	return manual_explode || (SDL_GetTicks() - created_at >= 3000) ;
}

void Bomb::setExploded(){
	manual_explode = true;
}
