#ifndef _ASSET_LOADER_H_
#define _ASSET_LOADER_H_

#include <map>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "Util.h"
#include "ExceptionLoader.h"

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
			BONUS_DECREASE_SPEED,

			PANEL
		};
	
		enum Sound {
			BOMB_EXPLODE,
			BONUS
		};

		static AssetLoader &getInstance();

		SDL_Surface *getSurface(Surface);
		SDL_Surface *getSurfaceFromText(const std::string &);
	
		Mix_Chunk *getSound(Sound);

	private:
		DISALLOW_COPY_AND_ASSIGN(AssetLoader)

		std::map<Surface, SDL_Surface *> surfaces;
		std::map<Sound, Mix_Chunk *> sounds;
		TTF_Font *font;
	
		AssetLoader() throw(ExceptionLoader);
		~AssetLoader();
		SDL_Surface *loadImageFromFile(const std::string &, bool) throw(ExceptionLoader);
};

#endif
