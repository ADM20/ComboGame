#include "scene_intro.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <system_renderer.h>
#include "system_resources.h"


using namespace std;
using namespace sf;
static double tempoTime = .5;//time between beats

Text text;

void IntroScene::Load() {
  cout << "Menu Load \n";
  {
	 
	  static Text t("COMBO TRAINER\nPRESS SPACE", *Resources::get<sf::Font>("RobotoMono-Regular.ttf"));
	  t.setFillColor(Color(100, 255, 255));
	  t.setPosition(Vcast<float>(Engine::getWindowSize()) * Vector2f(0.25f, 0.25f));
	  t.setCharacterSize(75);
	  t.setOutlineThickness(2);
	  t.setOutlineColor(sf::Color::White);
	  Renderer::queue(&t);
	 
}
  setLoaded(true);
}

void IntroScene::Update(const double& dt) {
	bool flag = true;
	RenderWindow &window = Engine::GetWindow();
	MusicLoader::load("music", true);
	MusicLoader::play();
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
				case sf::Keyboard::Space:
					Engine::ChangeScene(&menu);
					flag = false;
					break;
					// Don't forget to check for other events here
				}
			}
		}
	}
  Scene::Update(dt);
}
