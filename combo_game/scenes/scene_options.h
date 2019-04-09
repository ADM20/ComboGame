#pragma once

#include "engine.h"

class OptionsScene : public Scene {
public:
  OptionsScene() = default;
  ~OptionsScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};
