#include "cmp_attack.h"

using namespace std;
using namespace sf;

AttackComponent::AttackComponent(Entity* p) : Component(p)
{
	
}


void AttackComponent::Attack(Entity* oponent, int damage)
{
	oponent->addComponent<HitPointsComponent>()->changeHP(-damage);
	cout << damage << " damge done to " << oponent << endl;
}
