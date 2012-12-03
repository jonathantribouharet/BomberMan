#include "PanelComponent.h"

#include "AssetLoader.h"
#include "Convert.h"

using std::string;

PanelComponent::PanelComponent(const EntityId &id, int _index)
:EntityComponent(id),
index(_index),
position(Position(600, index * 150)){
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 200, 150,32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
	surface_background = AssetLoader::getInstance().getSurface(AssetLoader::PANEL);
	surface_userame = AssetLoader::getInstance().getSurfaceFromText(string("Player ") + toString(index + 1));

	surface_bombs = AssetLoader::getInstance().getSurfaceFromText("");
	surface_capacity = AssetLoader::getInstance().getSurfaceFromText("");
	surface_scope = AssetLoader::getInstance().getSurfaceFromText("");
	surface_speed = AssetLoader::getInstance().getSurfaceFromText("");    
}

PanelComponent::~PanelComponent(){
	SDL_FreeSurface(surface_userame);
	clearSurfaces();
}

SDL_Surface *PanelComponent::getSurface(){
	return surface;
}

Position &PanelComponent::getPosition(){
	return position;
}

SDL_Rect *PanelComponent::getScreenPosition(){
	sdl_position.x = position.getX();
	sdl_position.y = position.getY();

	return &sdl_position;
}

void PanelComponent::updateValues(unsigned int bombs, unsigned int capacity, unsigned int scope, float speed){
	clearSurfaces();

	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 200, 150,32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);

	surface_userame = AssetLoader::getInstance().getSurfaceFromText(string("Player ") + toString(index + 1));
	surface_bombs = AssetLoader::getInstance().getSurfaceFromText(string("bombs: ") + toString(bombs));
	surface_capacity = AssetLoader::getInstance().getSurfaceFromText(string("capacity: ") + toString(capacity));
	surface_scope = AssetLoader::getInstance().getSurfaceFromText(string("scope: ") + toString(scope));
	surface_speed = AssetLoader::getInstance().getSurfaceFromText(string("speed: ") + toString(speed));
	
	updateSurface(surface_background, 0, 0);
	updateSurface(surface_userame, 10, 10);
	updateSurface(surface_bombs, 10, 50);
	updateSurface(surface_capacity, 10, 70);
	updateSurface(surface_scope, 10, 90);
	updateSurface(surface_speed, 10, 110);
}

void PanelComponent::clearSurfaces(){
	SDL_FreeSurface(surface);
	SDL_FreeSurface(surface_bombs);
	SDL_FreeSurface(surface_capacity);
	SDL_FreeSurface(surface_scope);
	SDL_FreeSurface(surface_speed);
}

void PanelComponent::updateSurface(SDL_Surface *source, int x, int y){
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(source, NULL, surface, &offset);
}
