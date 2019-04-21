#include "engine.h"
#include "game.h"
#include <SFML/Audio.hpp>
using namespace std;

MenuScene menu;
Level1Scene level1;
Level2Scene level2;
OptionsScene optionsMenu;

int main() {
	sf::Music music;
	if (!music.openFromFile("res/audio/music.ogg"))
	{
		exit(0); // error
	}
	music.setPlayingOffset(sf::seconds(80.f));
	music.setLoop(true);
	music.play();
  Engine::Start(1280, 720, "Combo Trainer",&menu);
}