#ifndef _GRAPHIC_ENGINE_H_
#define _GRAPHIC_ENGINE_H_

#include "SDL.h"

#include "Engine.h"
#include "SystemComponent.h"
#include "PanelComponent.h"
#include "ExceptionLoader.h"

class GraphicEngine : public Engine{
	
	public:	
		GraphicEngine(GameContext &) throw(ExceptionLoader);
		virtual ~GraphicEngine();
	
		virtual void process();
		
	private:
		SDL_Surface *screen;
		Uint32 last_refresh;

		void synchronize();

		struct renderObject;
		struct renderPanel;

		template<class SystemComponent>
		void renderSystem(const SystemComponent &);

		void renderSystem(const SystemComponent<PanelComponent> &);
};

#endif
