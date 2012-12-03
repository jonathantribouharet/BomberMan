#include "Wall.h"

Wall::Wall(const EntityId &id, bool _is_destructible)
:EntityComponent(id),
is_destructible(_is_destructible){
}

bool Wall::isDestructible() const{
	return is_destructible;
}
