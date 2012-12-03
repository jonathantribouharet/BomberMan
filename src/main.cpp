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
	
	inputs.push_back(config_player_1);
}

int main(int argc, char *argv[]){
	std::vector<InputComponent::KeyboardConfig> inputs;
	createControlForPlayers(inputs);

	GameContext context;

	vector<Engine *> engines;

	engines.push_back(new InputEngine(context));
	engines.push_back(new GameEngine(context));
	engines.push_back(new GraphicEngine(context));

	LevelLoader::load("data/levels/1.map", context.componentContext, inputs);

	while (context.isRunning()){
		for(vector<Engine *>::const_iterator it = engines.begin(); it != engines.end(); ++it){
			(*it)->process();
		}		
	}

	for(vector<Engine *>::const_iterator it = engines.begin(); it != engines.end(); ++it){
		delete (*it);
	}

	return EXIT_SUCCESS;
}
