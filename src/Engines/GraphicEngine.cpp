#include "GraphicEngine.h"

#include <algorithm>

using std::for_each;

struct GraphicEngine::renderObject{
	
	public:
		renderObject(SDL_Surface *_screen, ComponentContext &_context)
		:screen(_screen),
		context(_context){
		}
		
		template<class Iterator>
		void operator()(Iterator &iter){
			RenderComponent *render = context.render_components.components[iter.first];
			SDL_BlitSurface(render->getSurface(), NULL, screen, render->getScreenPosition());
		}
	
	private:
		SDL_Surface *screen;
		ComponentContext &context;
};

template<class SystemComponent>
void GraphicEngine::renderSystem(const SystemComponent &system){
	for_each(system.components.begin(), system.components.end(), renderObject(screen, context.componentContext));
}

GraphicEngine::GraphicEngine(GameContext &context)
:Engine(context){
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_DOUBLEBUF) == -1){
		throw("SDL_Init failed");
	}

	SDL_EnableUNICODE(1);
		
	screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
	if(!screen){
		throw("SDL_SetVideoMode failed");
	}

	SDL_WM_SetCaption("BomberMan", "BomberMan");

	last_refresh = SDL_GetTicks();
}

GraphicEngine::~GraphicEngine(){
	SDL_Quit();
}

void GraphicEngine::process(){
	Uint32 now = SDL_GetTicks();
	context.componentContext.setSpeed((1000.0 / 60.0) / (now - last_refresh)); //60 FPS
	last_refresh = now;	

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0,0,0));

	renderSystem(context.componentContext.floors);
	renderSystem(context.componentContext.walls);
	renderSystem(context.componentContext.bonuses);
	renderSystem(context.componentContext.bombs);
	renderSystem(context.componentContext.bombermans);
	renderSystem(context.componentContext.blasts);	

	SDL_Flip(screen);
}
