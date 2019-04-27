#include "scene_level1.h"
#include "../components/cmp_player_physics.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_actor_movement.h"
#include "../components/cmp_bar_movement.h"
#include "../components/cmp_hp.h"
#include "../components/cmp_attack.h"
#include "../FighterFactory.h"
#include "../game.h"
#include <LevelSystem.h>
#include <iostream>
#include <thread>
#include <system_resources.h>
#include "engine.h"

using namespace std;
using namespace sf;

static shared_ptr<Entity> player;
static shared_ptr<Entity> playerHP;
static shared_ptr<Entity> bar;
static shared_ptr<Entity> tempo;
static shared_ptr<Entity> marker;
static shared_ptr<Entity> enemy;
static shared_ptr<Entity> enemyHP;

static double tempoTime = .48;//time between beats
Texture spritesheet;


int attackDamage = 5;
int missDamage = 10;

bool inputAllowed = true;//used to check if a key has already been pressed to stop multiple inputs


void Level3Scene::Load() {
	std::cout << " Scene 3 Load" << endl;//debug
	//increment levels unlocked
	if (SaveSystem::levelUnlocked < 3)
		SaveSystem::levelUnlocked = 3;

	ls::loadLevelFile("res/level_3.txt", 40.0f); //load level file 1

	//window
	auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
	ls::setOffset(Vector2f(0, ho));

	Vector2f playerSize(150.f, 300.f);
	// Create player
	{
		player = FighterFactory::newPlayer(player, playerHP, spritesheet, playerSize, enemy, this);
	}

	//create enemy
	{
		enemy = FighterFactory::newEnemy(enemy, enemyHP, spritesheet, playerSize, player, this);
	}


	//load tempo bar
	{
		marker = makeEntity();
		marker->setPosition(ls::getTilePosition(ls::findTiles(ls::TEMPO)[0])+Vector2f(20.f,0.f));
		auto t = marker->addComponent<ShapeComponent>();
		t->setShape<sf::RectangleShape>(Vector2f(10, 1000));
		t->getShape().setFillColor(Color::White);
	}

	//Hide Loading
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << " Scene 3 Load Done" << endl;
	//start music for this level
	MusicLoader::load("GuilesTheme", true);
	MusicLoader::play();
	setLoaded(true);
}

void Level3Scene::UnLoad() {
	std::cout << "Scene 3 Unload" << endl;
	MusicLoader::stop();
	player.reset();
	ls::unload();
	Scene::UnLoad();
}

void Level3Scene::Update(const double& dt) {
	Scene::Update(dt);
	if ((Keyboard::isKeyPressed(Keyboard::R))) {
		MusicLoader::loadSound("bloop");
		MusicLoader::playSound();
		UnLoad();
		Engine::ChangeScene((Scene*)&menu);
		MusicLoader::load("Megalovania", true);
		MusicLoader::play();
		return;
	}
	if ((Keyboard::isKeyPressed(Keyboard::P))) {
		MusicLoader::loadSound("bloop");
		MusicLoader::playSound();
		UnLoad();
		Engine::ChangeScene((Scene*)&level3);
		return;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Q))) {
		MusicLoader::loadSound("bloop");
		MusicLoader::playSound();
		exit(0);
	}

	if (ls::getTileAt(player->getPosition()) == ls::END) {
		UnLoad();
		Engine::ChangeScene((Scene*)&menu);
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
		bar->setPosition(ls::getTilePosition(ls::findTiles(ls::OBAR)[0]));
		auto s = bar->addComponent<ShapeComponent>();
		s->setShape<sf::RectangleShape>(Vector2f(25, 1000));
		s->getShape().setFillColor(Color::White);
		bar->addComponent<ObarMovementComponent>();//moves along until it reaches the end of the bar, then delete it

		bar = makeEntity();
		bar->setPosition(ls::getTilePosition(ls::findTiles(ls::BAR)[0]));
		auto b = bar->addComponent<ShapeComponent>();
		b->setShape<sf::RectangleShape>(Vector2f(25, 1000));
		b->getShape().setFillColor(Color::White);
		bar->addComponent<BarMovementComponent>();//moves along until it reaches the end of the bar, then delete it
	}

}

void Level3Scene::Render() {
	ls::render(Engine::GetWindow());
	Scene::Render();
}
