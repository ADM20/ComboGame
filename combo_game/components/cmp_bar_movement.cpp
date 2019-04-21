#include "cmp_bar_movement.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;


void BarMovementComponent::update(double dt)
{
		move(-0.5, 0.);	
}

BarMovementComponent::BarMovementComponent(Entity* p)
    : _speed(100.0f), Component(p) {}

bool BarMovementComponent::validMove(const sf::Vector2f& pos) {
   return (LevelSystem::getTileAt(pos) != LevelSystem::TEMPO);// until it reaches the tempo bar
  // return true;
}

void BarMovementComponent::move(const sf::Vector2f& p) {
  auto pp = _parent->getPosition() + p;
  if (validMove(pp)) {
    _parent->setPosition(pp);
  }
  else
  {
	  _parent->setForDelete();
  }
}

void BarMovementComponent::move(float x, float y) {
  move(Vector2f(x, y));
}
