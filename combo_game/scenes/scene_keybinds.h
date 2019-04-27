#pragma once

#include "engine.h"

class KeybindsScene : public Scene {
public:
  KeybindsScene() = default;
  ~KeybindsScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};
