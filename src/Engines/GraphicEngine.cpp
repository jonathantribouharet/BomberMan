#include "GraphicEngine.h"

#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <algorithm>

using std::for_each;

GraphicEngine::GraphicEngine(GameContext &context) throw(ExceptionLoader)
:Engine(context){
	//Initilaize SDL
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_DOUBLEBUF | SDL_INIT_AUDIO) == -1){
		throw ExceptionLoader("SDL_Init failed");
	}

	SDL_EnableUNICODE(1);

	if(TTF_Init() == -1){
		throw ExceptionLoader("TTF_Init failed");
	}
		
	screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
	if(!screen){
		throw ExceptionLoader("SDL_SetVideoMode failed");
	}
	
	SDL_WM_SetCaption("BomberMan", "BomberMan");

	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
		throw ExceptionLoader("Mix_OpenAudio failed");	
	}

	Mix_AllocateChannels(2);
	Mix_Volume(-1, MIX_MAX_VOLUME / 2);

	last_refresh = SDL_GetTicks();
}

GraphicEngine::~GraphicEngine(){
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
}

void GraphicEngine::process(){
	synchronize();

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0,0,0));

	renderSystem(context.componentContext.floors);
	renderSystem(context.componentContext.walls);
	renderSystem(context.componentContext.bonuses);
	renderSystem(context.componentContext.bombs);
	renderSystem(context.componentContext.bombermans);
	renderSystem(context.componentContext.blasts);	

	renderSystem(context.componentContext.panels);

	SDL_Flip(screen);
}

void GraphicEngine::synchronize(){
    Uint32 now = SDL_GetTicks();
    context.componentContext.setSpeed((1000.0 / 60.0) / (now - last_refresh));
    last_refresh = now;
}

// void GraphicEngine::synchronize(){
//     Uint32 now = SDL_GetTicks();
//     Uint32 next_time = last_refresh + (1000.0 / 60.0);

//     if(next_time > now){
//     	SDL_Delay(next_time - now);
//     	last_refresh = now;	
//     }
// }

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
