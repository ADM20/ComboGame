#pragma once
#include <ecm.h>

class BarMovementComponent : public Component {
protected:
  bool validMove(const sf::Vector2f&);
  float _speed;

public:
  void update(double dt) override;
  void move(const sf::Vector2f&);
  void move(float x, float y);
  void render() override {}
  explicit BarMovementComponent(Entity* p);
  BarMovementComponent() = delete;
};
