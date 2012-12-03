#ifndef _LEVEL_LOADER_H_
#define _LEVEL_LOADER_H_

#include "ComponentContext.h"

#include <vector>
#include <string>

class LevelLoader{
	
	public:
		static void load(const std::string &, ComponentContext &, std::vector<InputComponent::KeyboardConfig> &);
	
	private:
		enum MapSymbol{
			WALL_DESTRUCTIBLE = '*',
			WALL_INDESTRUCTIBLE = '#',
			BOMBERMAN = 'B',
			FLOOR = ' '
		};
};

#endif
