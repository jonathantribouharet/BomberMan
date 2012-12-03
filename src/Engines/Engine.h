#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Util.h"
#include "GameContext.h"

class Engine{
	
	public:
		Engine(GameContext &_context):context(_context){}
		virtual ~Engine(){}
		virtual void process() = 0;

	protected:
		GameContext &context;

	private:
		DISALLOW_COPY_AND_ASSIGN(Engine)
};

#endif
