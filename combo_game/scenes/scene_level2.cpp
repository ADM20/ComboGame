#include "scene_level2.h"
#include "../components/cmp_player_physics.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_actor_movement.h"
#include "../game.h"
#include <LevelSystem.h>
#include <iostream>
#include <thread>

using namespace std;
using namespace sf;

static shared_ptr<Entity> player;

void Level2Scene::Load() {
  std::cout << " Scene 2 Load" << endl;
  ls::loadLevelFile("res/level_1.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));
  Vector2f playerSize(150.f,300.f);
  // Create player
  {
    player = makeEntity();
    player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
    auto s = player->addComponent<ShapeComponent>();
    s->setShape<sf::RectangleShape>(playerSize);
    s->getShape().setFillColor(Color::Magenta);
    s->getShape().setOrigin(playerSize.x/2,playerSize.y/2);
	//add movement
	player->addComponent<ActorMovementComponent>();
  }


  //Simulate long loading times
  //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  std::cout << " Scene 2 Load Done" << endl;

  setLoaded(true);
}

void Level2Scene::UnLoad() {
  std::cout << "Scene 2 Unload" << endl;
  player.reset();
  ls::unload();
  Scene::UnLoad();
}

void Level2Scene::Update(const double& dt) {

  if (ls::getTileAt(player->getPosition()) == ls::END) {
    Engine::ChangeScene((Scene*)&optionsMenu);
  }
  //if(enemyHP < 0)
  //{
	//while(!key pressed)
	//{
	 //display victory overlay
	//}
  //Engine::ChangeScene((Scene*)&level2);
  //}
  Scene::Update(dt);
}

void Level2Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
