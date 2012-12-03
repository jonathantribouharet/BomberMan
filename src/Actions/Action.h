#ifndef _ACTION_H_
#define _ACTION_H_

class Action{
	
	public:
		virtual ~Action(){};
		virtual bool process() = 0; //Return true if action is finished
};

#endif
