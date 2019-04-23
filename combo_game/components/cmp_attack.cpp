#include "cmp_attack.h"

using namespace std;
using namespace sf;

AttackComponent::AttackComponent(Entity* p) : Component(p)
{
	
}


void AttackComponent::Attack(Entity* oponent, int damage)
{
	vector<shared_ptr<HitPointsComponent>> x = oponent->GetCompatibleComponent<HitPointsComponent>();
	x[0]->changeHP(-damage);
	cout << damage << " damge done" << endl;
}
