#pragma once

#include "engine.h"

class IntroScene : public Scene {
public:
  IntroScene() = default;
  ~IntroScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};
