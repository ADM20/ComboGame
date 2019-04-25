#include "musicLoader.h"

sf::Music music;
sf::SoundBuffer buffer;
sf::Sound sound;
float _soundVolume = 50.0f;
float _musicVolume = 50.0f;
void MusicLoader::load(std::string fileName)//default will loop
{
	if (!music.openFromFile("res/audio/" + fileName + ".wav")) //try to load the file given
	{
		exit(0); //if it doesent load throw error 
	}
	//music.setPlayingOffset(sf::seconds(80.f));
	music.setVolume(_musicVolume);
	music.setLoop(true);//loop music

}
void MusicLoader::load(std::string fileName, bool loop)//false to not loop to loop
{	
	if (!music.openFromFile("res/audio/"+fileName+".wav")) //try to load the file given
	{
		exit(0); //if it doesent load throw error 
	}
	//music.setPlayingOffset(sf::seconds(80.f));
	music.setVolume(_musicVolume);
	music.setLoop(loop);//loop music if true
	
}
void MusicLoader::play()
{
	music.play();
}
void MusicLoader::stop()
{
	music.stop();
}
void MusicLoader::setSoundVolume(float volume)
{
	_soundVolume = volume;
}
void MusicLoader::setMusicVolume(float volume)
{
	_musicVolume = volume;
}
void MusicLoader::playSound(std::string fileName)
{
	if (!buffer.loadFromFile("res/audio/"+fileName+".wav"))
	{
		exit(0);
	}
	sound.setBuffer(buffer);
	sound.setVolume(_soundVolume);
	sound.play();
}