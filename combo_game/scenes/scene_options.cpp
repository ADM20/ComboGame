#include "scene_options.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <system_renderer.h>

using namespace std;
using namespace sf;

void OptionsScene::Load() {
  cout << "Options Load \n";
  {
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>("Options Menu \n\n 1 - Keybinds \n 2 - Resolution \n  \n 3 - Menu");
  }
  setLoaded(true);
}

void OptionsScene::Update(const double& dt) {
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
					//call keybind scene
					flag = false;
					break;
				case sf::Keyboard::Num2:
					//call resolution selection scene
					flag = false;
					break;
				case sf::Keyboard::Num3:
					Engine::ChangeScene(&menu);
					flag = false;
					break;
				}
			}
		}
	}
  Scene::Update(dt);
}