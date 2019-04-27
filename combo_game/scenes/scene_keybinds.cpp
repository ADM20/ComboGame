#include "scene_keybinds.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <system_renderer.h>

using namespace std;
using namespace sf;
void KeybindsScene::Load() {
  cout << "Options Load \n";
  {
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>("Keybinds \n\n Choose a key to rebind\n 1 - UP\n 2- DOWN\n 3- LEFT \n 4 - RIGHT\n 5 - LK\n 6 - MK\n 7 HK \n 8 - LP\n 9 - MP\n [ - HP\n ] - CONFIRM \n\n R - Return to Menu");
  }
  setLoaded(true);
}

void KeybindsScene::Update(const double& dt) {
  //cout << "options Update "<<dt<<"\n";
	bool flag = true;
	RenderWindow &window = Engine::GetWindow();
	sf::Keyboard::Key rebind;

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
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::Up, rebind = event.key.code);
					flag = false;
					break;
				case sf::Keyboard::Num2:
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::Down, rebind = event.key.code);
					flag = false;
					break;
				case sf::Keyboard::Num3:
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::Left, rebind = event.key.code);
					flag = false;
					break;
				case sf::Keyboard::Num4:
					MusicLoader::loadSound("bleep");
 					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::Right, rebind = event.key.code);
					flag = false;
					break;
				case sf::Keyboard::Num5:
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::LightKick, rebind = event.key.code);

					flag = false;
					break;
				case sf::Keyboard::Num6:
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::MediumKick, rebind = event.key.code);

					flag = false;
					break;
				case sf::Keyboard::Num7:
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::HeavyKick, rebind = event.key.code);

					flag = false;
					break;
				case sf::Keyboard::Num8:
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::LightPunch, rebind = event.key.code);

					flag = false;
					break;
				case sf::Keyboard::Num9:
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::MediumPunch, rebind = event.key.code);

					flag = false;
					break;
				case sf::Keyboard::LBracket:
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::HeavyPunch, rebind = event.key.code);

					flag = false;
					break;
				case sf::Keyboard::RBracket:
					MusicLoader::loadSound("bleep");
					MusicLoader::playSound();
					InputManager::RebindKey(InputManager::Input::Confirm, rebind = event.key.code);

					flag = false;
					break;
				case sf::Keyboard::R:
					MusicLoader::loadSound("bloop");
					MusicLoader::playSound();
					Engine::ChangeScene(&optionsMenu);
					flag = false;
					break;
				}
			}
		}
	}
  Scene::Update(dt);
}
