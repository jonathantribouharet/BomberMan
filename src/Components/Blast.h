#ifndef _BLAST_COMPONENT_H_
#define _BLAST_COMPONENT_H_

#include "EntityComponent.h"

class Blast : public EntityComponent{
	
	public:
		Blast(const EntityId &, const EntityId &, unsigned int);
	
		EntityId getBomberanId() const;
		unsigned int getScope() const;
	
	private:
		const EntityId bomberman_id;
		const unsigned int scope;
};

#endif
