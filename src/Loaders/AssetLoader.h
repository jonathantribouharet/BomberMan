#ifndef _ASSET_LOADER_H_
#define _ASSET_LOADER_H_

#include <map>
#include <string>

#include "SDL.h"
#include "Util.h"

/*******WARNING*******
Must be call after init SDL for use SDL_DisplayFormat function
***********************/

class AssetLoader{
	
	public:
		enum Surface {
			BLAST_UP,
			BLAST_DOWN,
			BLAST_LEFT,
			BLAST_RIGHT,
			
			FLOOR,
			BLOCK_DESTRUCTIBLE,
			BLOCK_INDESTRUCTIBLE,
			
			BOMB,

			BOMBERMAN_UP,
			BOMBERMAN_DOWN,
			BOMBERMAN_LEFT,
			BOMBERMAN_RIGHT,
			
			BONUS_RANDOM,
			BONUS_INCREASE_BOMBS_CAPACITY,
			BONUS_DECREASE_BOMBS_CAPACITY,
			BONUS_INCREASE_BOMBS_SCOPE,
			BONUS_DECREASE_BOMBS_SCOPE,
			BONUS_INCREASE_SPEED,
			BONUS_DECREASE_SPEED
		};
	
		static AssetLoader & getInstance();
		
		SDL_Surface * getSurface(Surface);
	
	private:
		DISALLOW_COPY_AND_ASSIGN(AssetLoader)

		std::map<Surface, SDL_Surface *> surfaces;
	
		AssetLoader();
		~AssetLoader();
		SDL_Surface *loadImageFromFile(const std::string &, bool);
};

#endif
