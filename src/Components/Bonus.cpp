#include "Bonus.h"
#include "Randomizer.h"

Bonus::Bonus(const EntityId &id, BonusType _type)
:EntityComponent(id){
	if(_type == RANDOM){
		type = static_cast<BonusType>(Randomizer::getRandomValue(INCREASE_BOMBS_CAPACITY, DECREASE_SPEED));
	}
	else{
		type = _type;
	}
}

Bonus::BonusType Bonus::getType() const{
	return type;
}
