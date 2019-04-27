#include "ecm.h"
#include "components/cmp_player_physics.h"
#include "components/cmp_sprite.h"
#include "components/cmp_actor_movement.h"
#include "components/cmp_bar_movement.h"
#include "components/cmp_hp.h"
#include "components/cmp_attack.h"
#include "engine.h"
#include <LevelSystem.h>
#include <iostream>
#include <thread>
#include <system_resources.h>

using namespace std;
using namespace sf; 

class FighterFactory {
public:
	static shared_ptr<Entity> newEnemy(shared_ptr<Entity> e, shared_ptr<Entity> hpBar, shared_ptr<Entity> target);
	static shared_ptr<Entity> newPlayer(shared_ptr<Entity> p, shared_ptr<Entity> hpBar, Texture spritesheet, Vector2f size, shared_ptr<Entity> target, Level1Scene* sc);
};