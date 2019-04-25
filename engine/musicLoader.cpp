#include "musicLoader.h"

sf::Music music;

void MusicLoader::load(std::string fileName, bool loop)//true to loop
{	
	if (!music.openFromFile("res/audio/"+fileName+".wav")) //try to load the file given
	{
		exit(0); //if it doesent load throw error 
	}
	//music.setPlayingOffset(sf::seconds(80.f));
	music.setLoop(loop);//loop music
	
}
void MusicLoader::play()
{
	music.play();
}
void MusicLoader::stop()
{
	music.stop();
}