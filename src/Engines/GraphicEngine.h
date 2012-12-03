#ifndef _GRAPHIC_ENGINE_H_
#define _GRAPHIC_ENGINE_H_

#include "SDL.h"

#include "Engine.h"
#include "SystemComponent.h"

class GraphicEngine : public Engine{
	
	public:	
		GraphicEngine(GameContext &);
		virtual ~GraphicEngine();
	
		virtual void process();
		
	private:
		SDL_Surface *screen;
		Uint32 last_refresh;

		struct renderObject;

		template<class SystemComponent>
		void renderSystem(const SystemComponent &);
};

#endif
