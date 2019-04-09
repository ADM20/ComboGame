#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <system_renderer.h>


using namespace std;
using namespace sf;


void MenuScene::Load() {
  cout << "Menu Load \n";
  {
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>("Platformer \n1 - Load Test Level \n2 - Options");
  }
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {
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
					Engine::ChangeScene(&level3);
					flag = false;
					break;

				case sf::Keyboard::Num2:
					Engine::ChangeScene(&optionsMenu);
					flag = false;
					break;
					// Don't forget to check for other events here
				}
			}
		}
	}
  Scene::Update(dt);
}
