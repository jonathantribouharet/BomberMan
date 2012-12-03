#ifndef _ACTION_CONTEXT_H_
#define _ACTION_CONTEXT_H_

#include <queue>

#include "Util.h"
#include "Action.h"

class ActionContext{

	public:
		ActionContext();

		void pushAction(Action *);
		Action *popAction();
		bool haveActions() const;
		void switchActionsQueue();

	private:
		DISALLOW_COPY_AND_ASSIGN(ActionContext)

		bool actions_queue_in_use;
		std::queue<Action *> current_actions;
		std::queue<Action *> next_actions;
};

#endif
