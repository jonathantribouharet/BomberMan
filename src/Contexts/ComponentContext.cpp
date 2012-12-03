#include "ComponentContext.h"

#include "AssetLoader.h"
#include <algorithm>

#include "KeyboardInputComponent.h"
#include "LinearInputComponent.h"

#include "GenericBlockCollision.h"
#include "GenericDestroyCollision.h"
#include "BlastBlockCollision.h"
#include "BlastBombCollision.h"
#include "BombermanBlastCollision.h"
#include "BombermanBombCollision.h"
#include "BombermanBonusCollision.h"

using namespace std;

struct ComponentContext::deleteObject{
	template<class Iterator>
	void operator()(Iterator &iter){
		delete iter.second;
		iter.second = NULL;
	}
};

template<class SystemComponent>
void ComponentContext::deleteSystem(SystemComponent &system){
	for_each(system.components.begin(), system.components.end(), deleteObject());
}	

template<class SystemComponent>
void ComponentContext::deleteComponent(SystemComponent &system, const EntityComponent::EntityId &id){
	if(system.components.find(id) != system.components.end()){
		delete system.components[id];
		system.components[id] = NULL;
		system.components.erase(id);
	}
}

ComponentContext::ComponentContext()
:speed(1),
last_id(0){
	collider.registerCollision<Bomberman, Wall>(new GenericBlockCollision());
	collider.registerCollision<Bomberman, Bomb>(new BombermanBombCollision(*this));
	collider.registerCollision<Bomberman, Blast>(new BombermanBlastCollision(*this));
	collider.registerCollision<Bomberman, Bonus>(new BombermanBonusCollision(*this));
	
	collider.registerCollision<Blast, Wall>(new BlastBlockCollision(*this));
	collider.registerCollision<Blast, Bomb>(new BlastBombCollision(*this));
	collider.registerCollision<Blast, Bomberman>(new BombermanBlastCollision(*this));
	collider.registerCollision<Blast, Bonus>(new GenericDestroyCollision(*this));	
}

ComponentContext::~ComponentContext(){
	deleteSystem(components);
	deleteSystem(render_components);
	deleteSystem(input_components);
}

float ComponentContext::getSpeed() const{
	return speed;
}

void ComponentContext::setSpeed(const float &_speed){
	speed = _speed;
}

void ComponentContext::removeComponent(const EntityComponent::EntityId &id){
	deleteComponent(components, id);
	deleteComponent(render_components, id);
	deleteComponent(input_components, id);
	
	collisionables.components.erase(id);

	blasts.components.erase(id);
	bombs.components.erase(id);
	bombermans.components.erase(id);
	bonuses.components.erase(id);
	walls.components.erase(id);
	floors.components.erase(id);
}

bool ComponentContext::componentExist(const EntityComponent::EntityId &id){
	return components.components.find(id) != components.components.end();
}

vector<EntityComponent::EntityId> ComponentContext::createBlast(const Position &position, const EntityComponent::EntityId &bomberman_id, unsigned int scope){
	Position::Direction directions[] = {Position::UP, Position::DOWN, Position::LEFT, Position::RIGHT};
	InputComponent::InputAction actions[] = {InputComponent::GO_UP, InputComponent::GO_DOWN, InputComponent::GO_LEFT, InputComponent::GO_RIGHT};
	AssetLoader::Surface asset_surfaces[] = {AssetLoader::BLAST_UP, AssetLoader::BLAST_DOWN, AssetLoader::BLAST_LEFT, AssetLoader::BLAST_RIGHT};
	
	vector<EntityComponent::EntityId> ids;
	std::map<Position::Direction, SDL_Surface *> surfaces;
	
	for(int index = 0; index < 4; index++){
		surfaces.insert(std::make_pair(directions[index], AssetLoader::getInstance().getSurface(asset_surfaces[index])));
	}
	
	for(int index = 0; index < 4; index++){
		blasts.components[last_id] = new Blast(last_id, bomberman_id, scope);
		input_components.components[last_id] = new LinearInputComponent(last_id, actions[index]);
		render_components.components[last_id] = new RenderComponent(last_id, position, surfaces, directions[index], 3.0);
		collisionables.components[last_id] = render_components.components[last_id];
		components.components[last_id] = blasts.components[last_id];

		ids.push_back(last_id);

		last_id++;
	}	

	return ids;
}

void ComponentContext::createWall(const Position &position, bool isDestructible){
	SDL_Surface *surface;
	if(isDestructible){
		surface = AssetLoader::getInstance().getSurface(AssetLoader::BLOCK_DESTRUCTIBLE);
	}
	else{
		surface = AssetLoader::getInstance().getSurface(AssetLoader::BLOCK_INDESTRUCTIBLE);
	}
	
	walls.components[last_id] = new Wall(last_id, isDestructible);
	render_components.components[last_id] = new RenderComponent(last_id, position, surface);
	collisionables.components[last_id] = render_components.components[last_id];
	components.components[last_id] = walls.components[last_id];
	last_id++;	
}

EntityComponent::EntityId ComponentContext::createBomb(const Position &position, const EntityComponent::EntityId &bomberman_id){
	bombs.components[last_id] = new Bomb(last_id, bomberman_id, bombermans.components[bomberman_id]->getBombsScope());
	render_components.components[last_id] = new RenderComponent(last_id, position, AssetLoader::getInstance().getSurface(AssetLoader::BOMB));
	collisionables.components[last_id] = render_components.components[last_id];
	components.components[last_id] = bombs.components[last_id];

	return last_id++;
}

void ComponentContext::createBomberman(const Position &position, InputComponent::KeyboardConfig &keyboardConfig){
	Position::Direction directions[] = {Position::UP, Position::DOWN, Position::LEFT, Position::RIGHT};
	AssetLoader::Surface asset_surfaces[] = {AssetLoader::BOMBERMAN_UP, AssetLoader::BOMBERMAN_DOWN, AssetLoader::BOMBERMAN_LEFT, AssetLoader::BOMBERMAN_RIGHT};
	
	std::map<Position::Direction, SDL_Surface *> surfaces;
	
	for(int index = 0; index < 4; index++){
		surfaces.insert(std::make_pair(directions[index], AssetLoader::getInstance().getSurface(asset_surfaces[index])));
	}

	bombermans.components[last_id] = new Bomberman(last_id);
	render_components.components[last_id] = new RenderComponent(last_id, position, surfaces, Position::RIGHT, bombermans.components[last_id]->getSpeed());
	input_components.components[last_id] = new KeyboardInputComponent(last_id, keyboardConfig);	
	collisionables.components[last_id] = render_components.components[last_id];
	components.components[last_id] = bombermans.components[last_id];
	
	last_id++;		
}

void ComponentContext::createBonus(const Position & position, Bonus::BonusType type){
	SDL_Surface *sprite;
	switch(type){
		case Bonus::RANDOM:
			sprite = AssetLoader::getInstance().getSurface(AssetLoader::BONUS_RANDOM);
			break;
		case Bonus::INCREASE_BOMBS_CAPACITY:
			sprite = AssetLoader::getInstance().getSurface(AssetLoader::BONUS_INCREASE_BOMBS_CAPACITY);
			break;
		case Bonus::DECREASE_BOMBS_CAPACITY:
			sprite = AssetLoader::getInstance().getSurface(AssetLoader::BONUS_DECREASE_BOMBS_CAPACITY);
			break;
		case Bonus::INCREASE_BOMBS_SCOPE:
			sprite = AssetLoader::getInstance().getSurface(AssetLoader::BONUS_INCREASE_BOMBS_SCOPE);
			break;
		case Bonus::DECREASE_BOMBS_SCOPE:
			sprite = AssetLoader::getInstance().getSurface(AssetLoader::BONUS_DECREASE_BOMBS_SCOPE);
			break;
		case Bonus::INCREASE_SPEED:
			sprite = AssetLoader::getInstance().getSurface(AssetLoader::BONUS_INCREASE_SPEED);
			break;
		case Bonus::DECREASE_SPEED:
			sprite = AssetLoader::getInstance().getSurface(AssetLoader::BONUS_DECREASE_SPEED);
			break;
	}
	
	bonuses.components[last_id] = new Bonus(last_id, type);
	render_components.components[last_id] = new RenderComponent(last_id, position, sprite);
	collisionables.components[last_id] = render_components.components[last_id];
	components.components[last_id] = bonuses.components[last_id];

	last_id++;		
}

void ComponentContext::createFloor(const Position & position){
	floors.components[last_id] = new Floor(last_id);
	render_components.components[last_id] = new RenderComponent(last_id, position, AssetLoader::getInstance().getSurface(AssetLoader::FLOOR));
	components.components[last_id] = floors.components[last_id];
	
	last_id++;	
}
