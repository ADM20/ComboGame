#pragma once
#include <ecm.h>
#include "../components/cmp_sprite.h"
#include "../components/cmp_hp.h"
#include <SFML/Graphics.hpp>
#include "../game.h"

using namespace std;
using namespace sf;

class HitPointsComponent : public Component {
protected:
	int _hp;
	shared_ptr<Entity> _bar;
	shared_ptr<Entity> _self;

public:
	void update(double dt) override;
	void render() override {}
	explicit HitPointsComponent(Entity* p, int startHP);
	HitPointsComponent() = delete;
	void setBar(shared_ptr<Entity> bar);

	int getHP();
	void changeHP(int amount);
};
