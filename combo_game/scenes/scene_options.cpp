#include "scene_options.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void OptionsScene::Load() {
  cout << "Options Load \n";
  {
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>("Options Menu \n -- Add options here --\n 2 - Menu");
  }
  setLoaded(true);
}

void OptionsScene::Update(const double& dt) {
  //cout << "options Update "<<dt<<"\n";
	if (Keyboard::isKeyPressed(Keyboard::Num2)) {
		Engine::ChangeScene(&menu);
	}
  Scene::Update(dt);
}
