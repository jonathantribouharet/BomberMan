#ifndef _BONUS_COMPONENT_H_
#define _BONUS_COMPONENT_H_

#include "EntityComponent.h"

class Bonus : public EntityComponent{
	
	public:
		enum BonusType {
			RANDOM,
			INCREASE_BOMBS_CAPACITY,
			DECREASE_BOMBS_CAPACITY,
			INCREASE_BOMBS_SCOPE,
			DECREASE_BOMBS_SCOPE,
			INCREASE_SPEED,
			DECREASE_SPEED
		};
	
		Bonus(const EntityId &, BonusType);
		BonusType getType() const;
	
	private:
		BonusType type;
};

#endif
