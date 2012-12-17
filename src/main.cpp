#include <iostream>
#include <cstdlib>
#include <vector>

#include "InputEngine.h"
#include "GameEngine.h"
#include "GraphicEngine.h"

#include "LevelLoader.h"

using namespace std;

void createControlForPlayers(std::vector<InputComponent::KeyboardConfig> &inputs){
	InputComponent::KeyboardConfig config_player_1;
	config_player_1[InputComponent::GO_UP] = SDLK_UP;
	config_player_1[InputComponent::GO_DOWN] = SDLK_DOWN;
	config_player_1[InputComponent::GO_LEFT] = SDLK_LEFT;
	config_player_1[InputComponent::GO_RIGHT] = SDLK_RIGHT;
	config_player_1[InputComponent::PLANT_BOMB] = SDLK_SPACE;
	
	InputComponent::KeyboardConfig config_player_2;
	config_player_2[InputComponent::GO_UP] = SDLK_w;
	config_player_2[InputComponent::GO_DOWN] = SDLK_s;
	config_player_2[InputComponent::GO_LEFT] = SDLK_a;
	config_player_2[InputComponent::GO_RIGHT] = SDLK_d;
	config_player_2[InputComponent::PLANT_BOMB] = SDLK_e;

	inputs.push_back(config_player_1);
	inputs.push_back(config_player_2);
}

int main(int argc, char *argv[]){
	std::vector<InputComponent::KeyboardConfig> inputs;
	createControlForPlayers(inputs);

	GameContext context;
	vector<Engine *> engines;

	try{
		engines.push_back(new InputEngine(context));
		engines.push_back(new GameEngine(context));
		engines.push_back(new GraphicEngine(context));

		LevelLoader::load("data/levels/1.map", context.componentContext, inputs);
	}catch(ExceptionLoader e){
		std::cerr << e.what();
		return EXIT_FAILURE;
	}

	while(context.isRunning()){
		for(vector<Engine *>::const_iterator it = engines.begin(); it != engines.end(); ++it){
			(*it)->process();
		}		
	}

	for(vector<Engine *>::const_iterator it = engines.begin(); it != engines.end(); ++it){
		delete(*it);
	}

	return EXIT_SUCCESS;
}
