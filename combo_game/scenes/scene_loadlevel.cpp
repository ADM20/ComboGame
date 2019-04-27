#include "scene_loadlevel.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <system_renderer.h>

using namespace std;
using namespace sf;

void LoadScene::Load() {
  cout << "Options Load \n";
  {
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>("Level Selection\n1 - Level 1\n2 - Level 2\n3 - Level 3\nR - Return");
  }
  setLoaded(true);
}

void LoadScene::Update(const double& dt) {
  //cout << "options Update "<<dt<<"\n";
	bool flag = true;
	RenderWindow &window = Engine::GetWindow();
	while (flag)
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Num1:
					//if(scene 1 is unlocked){
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					Engine::ChangeScene(&level1);
					flag = false;
					break;
				case sf::Keyboard::Num2:
					Engine::ChangeScene(&level2);
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					flag = false;
					break;
				case sf::Keyboard::Num3:
					Engine::ChangeScene(&level3);
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					flag = false;
					break;
				case sf::Keyboard::R:
					MusicLoader::loadSound("bloop");
					MusicLoader::playSound();
					Engine::ChangeScene(&menu);
					flag = false;
					break;
					
				}
			}
		}
	}
  Scene::Update(dt);
}
