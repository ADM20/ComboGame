#pragma once

#include "engine.h"

class LoadScene : public Scene {
public:
  LoadScene() = default;
  ~LoadScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};
