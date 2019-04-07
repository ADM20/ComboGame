#include "engine.h"
#include "game.h"

using namespace std;

MenuScene menu;
Level1Scene level1;
OptionsScene optionsMenu;
Level3Scene level3;

int main() {
  Engine::Start(1280, 720, "Combo Trainer",&menu);
}