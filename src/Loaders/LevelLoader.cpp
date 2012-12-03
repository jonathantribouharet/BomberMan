#include "LevelLoader.h"

#include "Position.h"

#include <iostream>
#include <fstream>

using namespace std;

#define MAP_COMPONENT_SIZE 40

void LevelLoader::load(const string &path, ComponentContext &context, vector<InputComponent::KeyboardConfig> & inputs){
	unsigned int current_number_players = 0;
	ifstream file(path.c_str());
	
	if(!file){
		cerr << "Cannot open file : " + path << endl;
		throw;
	}
	
	string line;
	unsigned long current_line = 0;
	
	while(getline(file, line)){
		current_line++;
		for(unsigned int index = 0; index != line.size(); ++index){
			const char symbol = line[index];
			
			context.createFloor(Position((current_line - 1) * MAP_COMPONENT_SIZE, index * MAP_COMPONENT_SIZE));
			
			switch(symbol){
				case WALL_DESTRUCTIBLE:
					context.createWall(Position((current_line - 1) * MAP_COMPONENT_SIZE, index * MAP_COMPONENT_SIZE), true);
					break;
				case WALL_INDESTRUCTIBLE:
					context.createWall(Position((current_line - 1) * MAP_COMPONENT_SIZE, index * MAP_COMPONENT_SIZE), false);
					break;				
				case BOMBERMAN:
					if(current_number_players < inputs.size()){
						context.createBomberman(Position((current_line - 1) * MAP_COMPONENT_SIZE, index * MAP_COMPONENT_SIZE), inputs.at(current_number_players));
						current_number_players++;
					}
					break;				
				case FLOOR:
					break;
				default:
					cerr << "Malformated file, bad symbol line " << current_line << ": " << index << endl;
					throw;
			}
		}
	}
	
	if(current_number_players == 0){
		cerr << "No bomberman in map" << endl;
		throw;
	}
}
