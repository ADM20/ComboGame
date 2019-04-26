#include "cmp_attack.h"

using namespace std;
using namespace sf;

AttackComponent::AttackComponent(Entity* p) : Component(p)
{
	
}


void AttackComponent::Attack(Entity* oponentHpBar, int damage)
{
	vector<shared_ptr<HitPointsComponent>> x = oponentHpBar->GetCompatibleComponent<HitPointsComponent>();
	x[0]->changeHP(-damage);
	cout << damage << " damge done" << endl;
}
