#include <iostream>
#include <fstream>  
#include <SFML/Audio.hpp>

//used to handle music/sounds
class MusicLoader {
public:
	//ture to loop, false to stop at the end of song
	static void load(std::string fileName,bool loop);//attempt to load a new music file - Input name of file no extension or filepath required
	static void play();//play current music file
	static void stop();//stop current music file
};