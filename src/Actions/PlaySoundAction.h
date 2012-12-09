#ifndef _PLAY_SOUND_ACTION_H_
#define _PLAY_SOUND_ACTION_H_

#include "Action.h"
#include "AssetLoader.h"

class PlaySoundAction : public Action{
	
	public:
		PlaySoundAction(AssetLoader::Sound);
		virtual bool process();
	
	private:
		AssetLoader::Sound sound;
};

#endif