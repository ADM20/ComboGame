#include "cmp_attack.h"

using namespace std;
using namespace sf;

AttackComponent::AttackComponent(Entity* p, shared_ptr<Entity> t) : Component(p)
{
	_target = t;
}


void AttackComponent::Attack(int damage)
{
	_target->GetCompatibleComponent<HitPointsComponent>()[0]->changeHP(-damage);
	cout << damage << " damge done" << endl;
}
