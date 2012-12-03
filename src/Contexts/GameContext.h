#ifndef _GAME_CONTEXT_H_
#define _GAME_CONTEXT_H_

#include "Util.h"
#include "ActionContext.h"
#include "ComponentContext.h"

class GameContext{

	public:
		ActionContext actionContext;
		ComponentContext componentContext;

		GameContext();

		bool isRunning() const;
		void setRunning(bool);

	private:
		DISALLOW_COPY_AND_ASSIGN(GameContext)
		bool is_running;
};

#endif
