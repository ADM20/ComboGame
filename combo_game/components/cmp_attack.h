#pragma once
#include <ecm.h>
#include "cmp_hp.h"

class AttackComponent : public Component {

public:
	void update(double dt) override {};
	void render() override {}
	explicit AttackComponent(Entity* p);
	AttackComponent() = delete;

	void Attack(Entity* oponent, int damage);
};
