#include "scene_level1.h"
#include "../components/cmp_player_physics.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_actor_movement.h"
#include "../components/cmp_bar_movement.h"
#include "../components/cmp_hp.h"
#include "../components/cmp_attack.h"
#include "../game.h"
#include <LevelSystem.h>
#include <iostream>
#include <thread>
#include <system_resources.h>

using namespace std;
using namespace sf;
Vector2f barSize(100, 10);

static shared_ptr<Entity> player;
static shared_ptr<Entity> playerHP;
static shared_ptr<Entity> bar;
static shared_ptr<Entity> tempo;
static shared_ptr<Entity> marker;
static shared_ptr<Entity> enemy;
static shared_ptr<Entity> enemyHP;

static double tempoTime = .48;//time between beats
Texture spritesheet;
void Level1Scene::Load() {
	std::cout << " Scene 1 Load" << endl;//debug

	ls::loadLevelFile("res/level_1.txt", 40.0f); //load level file 1

	//window
	auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
	ls::setOffset(Vector2f(0, ho));




	Vector2f playerSize(150.f, 300.f);
	// Create player
	{
		if (!spritesheet.loadFromFile("res/img/invaders/invaders_sheet.png")) {
			cerr << "Failed to load spritesheet!" << std::endl;
		}
		auto rect = IntRect(32, 0, 32, 32);
		player = makeEntity();
		player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
		//add sprites
		auto s = player->addComponent<ShapeComponent>();
		//pSprite->setTexure(Resources::get<Texture>("res/img/char_3.png"));
		s->setShape<sf::RectangleShape>(playerSize);
		s->getShape().setFillColor(Color::Magenta);
		s->getShape().setOrigin(playerSize.x / 2, playerSize.y / 2);
		//add movement
		player->addComponent<ActorMovementComponent>();



		//bar to show HP
		playerHP = makeEntity();
		auto hp = playerHP->addComponent<ShapeComponent>();
		hp->setShape<sf::RectangleShape>(barSize);
		hp->getShape().setFillColor(Color::Green);
		hp->getShape().setOrigin(barSize.x / 2, barSize.y / 2);
		playerHP->setPosition({ player->getPosition().x, player->getPosition().y -200 });

		//add HP
		player->addComponent<HitPointsComponent>(100);
		player->GetCompatibleComponent<HitPointsComponent>()[0]->setBar(playerHP);

		//set enemy as target of attacks
		player->addComponent<AttackComponent>(enemy);
	}

	//create enemy
	{
		if (!spritesheet.loadFromFile("res/img/invaders/invaders_sheet.png")) {
			cerr << "Failed to load spritesheet!" << std::endl;
		}
		auto rect = IntRect(32, 0, 32, 32);
		enemy = makeEntity();
		enemy->setPosition(ls::getTilePosition(ls::findTiles(ls::END)[0]));
		//add sprites
		auto s = enemy->addComponent<ShapeComponent>();
		//pSprite->setTexure(Resources::get<Texture>("res/img/char_3.png"));
		s->setShape<sf::RectangleShape>(playerSize);
		s->getShape().setFillColor(Color::Yellow);
		s->getShape().setOrigin(playerSize.x / 2, playerSize.y / 2);
		//add movement
		enemy->addComponent<ActorMovementComponent>();

		//bar to show HP
		enemyHP = makeEntity();
		auto hp = enemyHP->addComponent<ShapeComponent>();
		hp->setShape<sf::RectangleShape>(barSize);
		hp->getShape().setFillColor(Color::Red);
		hp->getShape().setOrigin(barSize.x / 2, barSize.y / 2);
		enemyHP->setPosition({ enemy->getPosition().x, enemy->getPosition().y - 200 });

		//add HP
		enemy->addComponent<HitPointsComponent>(100);
		enemy->GetCompatibleComponent<HitPointsComponent>()[0]->setBar(enemyHP);

		//set it to attack the player
		enemy->addComponent<AttackComponent>(player);

		enemy->GetCompatibleComponent<AttackComponent>()[0]->Attack(80);
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
	MusicLoader::load("GuilesTheme", true);
	MusicLoader::play();
	setLoaded(true);
}

void Level1Scene::UnLoad() {
	std::cout << "Scene 1 Unload" << endl;
	MusicLoader::stop();
	player.reset();
	bar.reset();
	ls::unload();
	Scene::UnLoad();
}

void Level1Scene::Update(const double& dt) {
	Scene::Update(dt);
	if ((Keyboard::isKeyPressed(Keyboard::R))) {
		MusicLoader::playSound("bloop");
		UnLoad();
		Engine::ChangeScene((Scene*)&menu);
		MusicLoader::load("Megalovania", true);
		MusicLoader::play();
		return;
	}
	if ((Keyboard::isKeyPressed(Keyboard::P))) {
		MusicLoader::playSound("bloop");
		UnLoad();
		Engine::ChangeScene((Scene*)&level1);
		return;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Q))) {
		MusicLoader::playSound("bloop");
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
