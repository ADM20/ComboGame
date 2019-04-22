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
