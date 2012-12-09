#include "PlaySoundAction.h"

PlaySoundAction::PlaySoundAction(AssetLoader::Sound _sound)
:sound(_sound){
}

bool PlaySoundAction::process(){
	Mix_PlayChannel(sound, AssetLoader::getInstance().getSound(sound), 0);
	return true;
}
