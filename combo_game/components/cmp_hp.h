#pragma once
#include <ecm.h>

class HitPointsComponent : public Component {
protected:
	float _hp;

public:
	void update(double dt) override {};
	void render() override {}
	explicit HitPointsComponent(Entity* p, int startHP);
	HitPointsComponent() = delete;

	int getHP();
	void changeHP(int amount);
};
