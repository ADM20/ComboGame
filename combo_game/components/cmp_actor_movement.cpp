#include "cmp_actor_movement.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;

static double elapsed = 0;
double tempo = .5;
double grace = .15;
bool flag = true;

void ActorMovementComponent::update(double dt) 
{
	
	elapsed -= dt;
	RenderWindow &window = Engine::GetWindow();
	if (((Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D))) && flag == true && elapsed >= (0.0 + grace)) // if we are not in grace period
	{
		//std::cout << "You MISSED!!" << endl;
		flag = false; // key pressed
	}

	//if we are in grace period
	if (elapsed <= (0.0 + grace))
	{
		//circle spwans when you can input 
		///TEST CODE PLEASE REMOVE///
		sf::CircleShape shape(50);
		shape.setFillColor(sf::Color(100, 250, 50));
		shape.setPosition(50.,50.);
		window.draw(shape);
		///REMOVE ABOVE ////

		//if we ran out of time
		if (elapsed < (0.0 - grace))
		{
			if (flag == true) //if we did not hit a correct key we missed the input
			{
				//std::cout << "Missed" << endl;
			}
			flag = true;
			elapsed = tempo;
		}
		//take input
		if ((Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D)) && flag == true)
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
				}
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
