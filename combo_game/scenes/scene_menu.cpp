#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void MenuScene::Load() {
  cout << "Menu Load \n";
  {
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>("Platformer\nPress Space to Start \n1 - Load Test Level \n2 - Options");
  }
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {
  // cout << "Menu Update "<<dt<<"\n";

  if (sf::Keyboard::isKeyPressed(Keyboard::Space)) {
    Engine::ChangeScene(&level1);
  }
  //Start Game
  else if (sf::Keyboard::isKeyPressed(Keyboard::Num1)) {  
	  Engine::ChangeScene(&level3);
  }
  //Options Menu
  else if (sf::Keyboard::isKeyPressed(Keyboard::Num2)) {
	  Engine::ChangeScene(&optionsMenu);
  }
  Scene::Update(dt);
}
