#include "LevelLoader.h"

#include "Position.h"
#include "Convert.h"

#include <fstream>

using namespace std;

void LevelLoader::load(const string &path, ComponentContext &context, vector<InputComponent::KeyboardConfig> &inputs) throw(ExceptionLoader){
	context.mapContext.cellWidth = 40;
	context.mapContext.cellHeight = 40;
	context.mapContext.bombermanWidth = 20;
	context.mapContext.bombermanHeight = 30;

	unsigned int current_number_players = 0;
	ifstream file(path.c_str());
	
	if(!file){
		throw ExceptionLoader("Cannot open file : " + path);
	}
	
	string line;
	unsigned long current_line = 0;
	
	while(getline(file, line)){
		current_line++;
		for(unsigned int index = 0; index < line.size(); ++index){
			const char symbol = line[index];
			
			Position current_position = Position(index * context.mapContext.cellWidth, (current_line - 1) * context.mapContext.cellHeight);

			context.createFloor(current_position);
			
			switch(symbol){
				case WALL_DESTRUCTIBLE:
					context.createWall(current_position, true);
					break;
				case WALL_INDESTRUCTIBLE:
					context.createWall(current_position, false);
					break;				
				case BOMBERMAN:
					if(current_number_players < inputs.size()){
						context.createBomberman(current_position, inputs.at(current_number_players));
						current_number_players++;
					}
					break;				
				case FLOOR:
					break;
				default:
					throw ExceptionLoader("Malformated file, bad symbol line " + toString(current_line) + ": " + toString(index));
			}
		}
	}
	
	if(current_number_players == 0){
		throw ExceptionLoader("No bomberman in map");
	}
}
