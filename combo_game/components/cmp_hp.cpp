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
	cout << "new hp = " << _hp << endl;
}

void HitPointsComponent::setBar(shared_ptr<Entity> bar, Color c)
{
	_bar = bar;
	_barCol = c;
}

void HitPointsComponent::update(double dt)
{
	
	float percentage = (_hp / 100.0f);

	Vector2f barSize(100, 10);
	Vector2f displayBarScale(percentage, 1);

	Vector2f output = barSize * displayBarScale;
	if (output.y < 0)
		output.y = 0;
	cout << output.y << endl;
	auto b = _bar->GetCompatibleComponent<ShapeComponent>()[0];
	b->setShape<sf::RectangleShape>(output);
	b->getShape().setFillColor(_barCol);
	b->getShape().setOrigin(barSize.x / 2, barSize.y / 2);

	_bar->setPosition({_parent->getPosition().x, _parent->getPosition().y - 200});
}
