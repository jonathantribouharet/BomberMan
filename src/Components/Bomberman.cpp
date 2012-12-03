#include "Bomberman.h"

Bomberman::Bomberman(const EntityId &id)
:EntityComponent(id),
bombs_capacity(1),
bombs_scope(1),
bombs(bombs_capacity),
speed(2.0){
}

unsigned int Bomberman::getBombs() const{
	return bombs;
}

void Bomberman::increaseBombs(){
	if(bombs < bombs_capacity){
		bombs++;
	}
}

void Bomberman::decreaseBombs(){
	if(bombs > 0){
		bombs--;
	}
}

unsigned int Bomberman::getBombsScope() const{
	return bombs_scope;
}

void Bomberman::increaseBombsScope(){
	bombs_scope++;
}

void Bomberman::decreaseBombsScope(){
	if(bombs_scope > 1){
		bombs_scope--;	
	}
}

unsigned int Bomberman::getBombsCapacity() const{
	return bombs_capacity;
}

void Bomberman::increaseBombsCapacity(){
	bombs_capacity++;
}

void Bomberman::decreaseBombsCapacity(){
	if(bombs_capacity > 1){
		bombs_capacity--;	
	}
}

float Bomberman::getSpeed() const{
	return speed;
}

void Bomberman::increaseSpeed(){
	if(speed < 4.0){
		speed += 0.5;
	}
}

void Bomberman::decreaseSpeed(){
	if(speed > 1){
		speed -= 0.5;	
	}
}
