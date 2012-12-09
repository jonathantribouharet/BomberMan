#include "AssetLoader.h"

#include <iostream>
#include "SDL_image.h"

using namespace std;

AssetLoader &AssetLoader::getInstance(){
	static AssetLoader *instance = NULL;

	if(instance == NULL){
		instance = new AssetLoader();
	}

	return *instance;
}

AssetLoader::AssetLoader() throw(ExceptionLoader){
	surfaces.insert(make_pair(BLAST_UP, loadImageFromFile("data/images/blast/blast-up.png", true)));
	surfaces.insert(make_pair(BLAST_DOWN, loadImageFromFile("data/images/blast/blast-down.png", true)));
	surfaces.insert(make_pair(BLAST_LEFT, loadImageFromFile("data/images/blast/blast-left.png", true)));
	surfaces.insert(make_pair(BLAST_RIGHT, loadImageFromFile("data/images/blast/blast-right.png", true)));
	
	surfaces.insert(make_pair(FLOOR, loadImageFromFile("data/images/floor.png", true)));
	surfaces.insert(make_pair(BLOCK_DESTRUCTIBLE, loadImageFromFile("data/images/block.bmp", false)));
	surfaces.insert(make_pair(BLOCK_INDESTRUCTIBLE, loadImageFromFile("data/images/wall.bmp", false)));
	
	surfaces.insert(make_pair(BOMB, loadImageFromFile("data/images/bomb.png", true)));

	surfaces.insert(make_pair(BOMBERMAN_UP, loadImageFromFile("data/images/bomberman/bomberman-up.png", true)));
	surfaces.insert(make_pair(BOMBERMAN_DOWN, loadImageFromFile("data/images/bomberman/bomberman-down.png", true)));
	surfaces.insert(make_pair(BOMBERMAN_LEFT, loadImageFromFile("data/images/bomberman/bomberman-left.png", true)));
	surfaces.insert(make_pair(BOMBERMAN_RIGHT, loadImageFromFile("data/images/bomberman/bomberman-right.png", true)));
	
	surfaces.insert(make_pair(BONUS_RANDOM, loadImageFromFile("data/images/bonus/random.png", true)));
	surfaces.insert(make_pair(BONUS_INCREASE_BOMBS_CAPACITY, loadImageFromFile("data/images/bonus/increase_capacity.png", true)));
	surfaces.insert(make_pair(BONUS_DECREASE_BOMBS_CAPACITY, loadImageFromFile("data/images/bonus/decrease_capacity.png", true)));
	surfaces.insert(make_pair(BONUS_INCREASE_BOMBS_SCOPE, loadImageFromFile("data/images/bonus/increase_scope.png", true)));
	surfaces.insert(make_pair(BONUS_DECREASE_BOMBS_SCOPE, loadImageFromFile("data/images/bonus/decrease_scope.png", true)));
	surfaces.insert(make_pair(BONUS_INCREASE_SPEED, loadImageFromFile("data/images/bonus/increase_speed.png", true)));
	surfaces.insert(make_pair(BONUS_DECREASE_SPEED, loadImageFromFile("data/images/bonus/decrease_speed.png", true)));

	surfaces.insert(make_pair(PANEL, loadImageFromFile("data/images/panel.png", true)));

	sounds.insert(make_pair(BOMB_EXPLODE, Mix_LoadWAV("data/sounds/bomb.wav")));
	sounds.insert(make_pair(BONUS, Mix_LoadWAV("data/sounds/bonus.wav")));


	font = TTF_OpenFont("data/font.ttf", 15);

	if(!font){
		throw ExceptionLoader("Cannot load data/menu_font.ttf");
	}
}

AssetLoader::~AssetLoader(){
	for(map<Surface, SDL_Surface *>::const_iterator it = surfaces.begin(); it != surfaces.end(); ++it){
		SDL_FreeSurface(it->second);
	}
	for(map<Sound, Mix_Chunk *>::const_iterator it = sounds.begin(); it != sounds.end(); ++it){
		Mix_FreeChunk(it->second);
	}
	TTF_CloseFont(font);
}

SDL_Surface *AssetLoader::getSurface(Surface key){
	return surfaces[key];
}

SDL_Surface *AssetLoader::getSurfaceFromText(const std::string & text){
    SDL_Color fontcolor = {0, 0, 0};
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), fontcolor);	
	return surface;
}

SDL_Surface *AssetLoader::loadImageFromFile(const string & path, bool isTransparent) throw(ExceptionLoader){
	SDL_Surface *surface = IMG_Load(path.c_str());
	
	if(surface == NULL){
		throw ExceptionLoader("Cannot load file: " + path);
	}
		
	if(isTransparent){
		SDL_SetColorKey(surface, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, 255, 255, 255));
	}
	else{
		SDL_Surface *optimized_surface = SDL_DisplayFormat(surface);
		SDL_FreeSurface(surface);
		surface = optimized_surface;
	}
		
	return surface;	
}

Mix_Chunk *AssetLoader::getSound(Sound key){
	return sounds[key];
}
