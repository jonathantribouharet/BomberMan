#ifndef _RANDOMIZER_H_
#define _RANDOMIZER_H_

#include <cstdlib>

class Randomizer{
	
	public:
		//Interval [min, max]
		static unsigned int getRandomValue(unsigned int min, unsigned int max){
			return (rand() % (max - min + 1)) + min;
		}
};

#endif
