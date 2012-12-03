#include "GameContext.h"

GameContext::GameContext()
:is_running(true){
}

bool GameContext::isRunning() const{
	return is_running;
}

void GameContext::setRunning(bool _is_running){
	is_running = _is_running;
}
