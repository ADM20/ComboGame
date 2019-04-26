#pragma once
#include <ecm.h>

class ObarMovementComponent : public Component {
protected:
  bool validMove(const sf::Vector2f&);
  float _speed;

public:
  void update(double dt) override;
  void move(const sf::Vector2f&);
  void move(float x, float y);
  void render() override {}
  explicit ObarMovementComponent(Entity* p);
  ObarMovementComponent() = delete;
};
