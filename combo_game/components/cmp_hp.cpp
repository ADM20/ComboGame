#include "cmp_hp.h"

using namespace std;
using namespace sf;

HitPointsComponent::HitPointsComponent(Entity* p, int startAmount) : Component(p)
{
	cout << "start with " << startAmount << "HP" << endl;
	_hp = 100;
}


int HitPointsComponent::getHP()
{
	cout << "hp = " << _hp << endl;
	return _hp;
}

void HitPointsComponent::changeHP(int amount)
{
	_hp += amount;
}

void HitPointsComponent::setBar(shared_ptr<Entity> bar)
{
	cout << "bar set" << endl;
	_bar = bar;
}

void HitPointsComponent::update(double dt)
{
	double percentage = (_hp / 100);

	Vector2f barSize(100, 10);
	Vector2f displayBarSize(barSize.x, barSize.y * percentage);

	

	_bar->setPosition({_parent->getPosition().x, _parent->getPosition().y - 200});
}
