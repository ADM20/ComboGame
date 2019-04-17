#include "cmp_actor_movement.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;

static double elapsed = 0;
double tempo = .5;
double grace = 0.5;
bool flag = true;

void ActorMovementComponent::update(double dt) 
{
	
	elapsed -= dt;

	if (((0-grace)<elapsed <=(0+grace))&&flag == true)
	{
		std::cout << "NOW!" << endl;
		if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D))
		{
			//step right
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				std::cout << "Move Right" << endl;
			}
			//step left
			else
			{
				std::cout << "Move Left" << endl;
			}
			flag = false;
			elapsed = tempo;
		}
		
	}
	else if ((Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D))&& flag == true )
	{
		std::cout << "Miss Timed" << endl;
		flag = false;
	}
	 if(elapsed<(0-grace))
	{
		flag = true;
		elapsed = tempo;
		std::cout << "Missed" << endl;	
	}
	
	
}

ActorMovementComponent::ActorMovementComponent(Entity* p)
    : _speed(100.0f), Component(p) {}

bool ActorMovementComponent::validMove(const sf::Vector2f& pos) {
  return (LevelSystem::getTileAt(pos) != LevelSystem::WALL);
  // return true;
}

void ActorMovementComponent::move(const sf::Vector2f& p) {
  auto pp = _parent->getPosition() + p;
  if (validMove(pp)) {
    _parent->setPosition(pp);
  }
}

void ActorMovementComponent::move(float x, float y) {
  move(Vector2f(x, y));
}
