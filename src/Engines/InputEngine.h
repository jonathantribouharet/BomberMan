#ifndef _INPUT_ENGINE_H_
#define _INPUT_ENGINE_H_

#include "Engine.h"

class InputEngine : public Engine{
	
	public:	
		InputEngine(GameContext &);
		virtual void process();
};

#endif
