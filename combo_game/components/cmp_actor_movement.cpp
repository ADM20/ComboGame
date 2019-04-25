#include "cmp_actor_movement.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;


bool flag = true;//used to check if a key has already been pressed to stop multiple inputs

void ActorMovementComponent::update(double dt) 
{
	RenderWindow &window = Engine::GetWindow();
	if (((Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D))) && flag == true && !(InputManager::getBool())) // if we are not in grace period
	{
		//InputManager::GetInput(InputManager::Input::Down, InputManager::Mode::IsPressed)
		//play a sound
		//std::cout << "You MISSED!!" << endl;
		flag = false; // key pressed
	}
	if (!flag && !InputManager::getBool())
	{
		flag =true;
	}

		//take input
		if ((Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D)) && flag == true && InputManager::getBool())
				{
					//step right
					if (Keyboard::isKeyPressed(Keyboard::D))
					{
						std::cout << "Move Right" << endl;
						move(100,0);
					}
					//step left
					else
					{
						std::cout << "Move Left" << endl;
						move(-100, 0);
											}
					flag = false; // key pressed
					//play a sound
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
