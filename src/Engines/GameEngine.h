#ifndef _GAME_ENGINE_H_
#define _GAME_ENGINE_H_

#include "Engine.h"

class GameEngine : public Engine{
	
	public:	
		GameEngine(GameContext &);
		virtual void process();
};

#endif
