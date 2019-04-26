#pragma once
#include <ecm.h>
#include "../components/cmp_sprite.h"
#include "../components/cmp_hp.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class AttackComponent : public Component {
protected:
	shared_ptr<Entity> _target;
public:
	void update(double dt) override {};
	void render() override {}
	explicit AttackComponent(Entity* p, shared_ptr<Entity> t);
	AttackComponent() = delete;

	void Attack(int damage);
};
