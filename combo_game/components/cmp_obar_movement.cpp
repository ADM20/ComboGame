#include "cmp_obar_movement.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;
static shared_ptr<Entity> hitMarker;


void ObarMovementComponent::update(double dt)
{
		move(0.5, 0.);	
		if (LevelSystem::getTileAt(_parent->getPosition()) == LevelSystem::INPUT)//when the bar reaches the input section, take input
		{
			//take input now
		}
}

ObarMovementComponent::ObarMovementComponent(Entity* p)
    : _speed(100.0f), Component(p) {}

bool ObarMovementComponent::validMove(const sf::Vector2f& pos) {//when it reaches the tempo bar, delete it
   return (LevelSystem::getTileAt(pos) != LevelSystem::TEMPO);
  // return true;
}


void ObarMovementComponent::move(const sf::Vector2f& p) {
  auto pp = _parent->getPosition() + p;
  if (validMove(pp)) {
    _parent->setPosition(pp);
  }
  else
  {
	  //play a sound for when deleted
	  InputManager::setBool(0.1f);
	  _parent->setForDelete();
  }
}

void ObarMovementComponent::move(float x, float y) {
  move(Vector2f(x, y));
}
