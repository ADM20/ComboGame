#include "scene_level1.h"
#include "../components/cmp_player_physics.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_actor_movement.h"
#include "../components/cmp_bar_movement.h"
#include "../game.h"
#include <LevelSystem.h>
#include <iostream>
#include <thread>

using namespace std;
using namespace sf;

static shared_ptr<Entity> player;
static shared_ptr<Entity> bar;
static shared_ptr<Entity> tempo;
static shared_ptr<Entity> marker;
static double tempoTime = .5;//time between beats

void Level1Scene::Load() {
  std::cout << " Scene 1 Load" << endl;
  ls::loadLevelFile("res/level_1.txt", 40.0f); //load level file 1

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

   
  //load tempo bar
  {
	  tempo = makeEntity();
	  tempo->setPosition(ls::getTilePosition(ls::findTiles(ls::TEMPO)[0]));
	  auto s = tempo->addComponent<ShapeComponent>();
	  s->setShape<sf::RectangleShape>(Vector2f(900, 30));
	  s->getShape().setFillColor(Color::Blue);

	  
	  marker = makeEntity();
	  marker->setPosition(ls::getTilePosition(ls::findTiles(ls::TEMPO)[0]));
	  auto t = marker->addComponent<ShapeComponent>();
	  t->setShape<sf::RectangleShape>(Vector2f(40, 60));
	  t->getShape().setFillColor(Color::White);

	   
  }

  //Hide Loading
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  std::cout << " Scene 1 Load Done" << endl;
  //start music for this level
  MusicLoader::load("music",true);
  MusicLoader::play();
  setLoaded(true);
}

void Level1Scene::UnLoad() {
  std::cout << "Scene 1 Unload" << endl;
  player.reset();
  ls::unload();
  Scene::UnLoad();
}

void Level1Scene::Update(const double& dt) {
	Scene::Update(dt);
	if((Keyboard::isKeyPressed(Keyboard::R))){ 
		Engine::ChangeScene((Scene*)&level1);
		return; 
	}
	if ((Keyboard::isKeyPressed(Keyboard::Q))) {
		exit(0);
	}

  if (ls::getTileAt(player->getPosition()) == ls::END) {
    Engine::ChangeScene((Scene*)&level2);
  }
  //if(enemyHP < 0)
  //{
	//while(!key pressed)
	//{
	 //display victory overlay
	//}
  // MusicLoader::stop();
  //Engine::ChangeScene((Scene*)&level2);
  //}
  static double barTime = 0.0f;
  barTime -= dt;

  if (barTime <= 0.f)//spawn a new bar every x seconds
  {
	  barTime = tempoTime;//where x = tempo time
	  bar = makeEntity();
	  bar->setPosition(ls::getTilePosition(ls::findTiles(ls::BAR)[0]));
	  auto b = bar->addComponent<ShapeComponent>();
	  b->setShape<sf::RectangleShape>(Vector2f(10, 40));
	  b->getShape().setFillColor(Color::Magenta);
	  bar->addComponent<BarMovementComponent>();//moves along until it reaches the end of the bar, then delete it
  }
  
}

void Level1Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
