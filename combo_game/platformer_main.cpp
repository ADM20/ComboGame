#include "engine.h"
#include "game.h"

using namespace std;

LoadScene loadScene;
MenuScene menu;
Level1Scene level1;
Level2Scene level2;
OptionsScene optionsMenu;


int main() {
  Engine::Start(1280, 720, "Combo Trainer",&menu);
}