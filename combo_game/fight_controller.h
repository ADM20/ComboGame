#pragma once
#include <LevelSystem.h>
#include <iostream>
#include "engine.h"
#include <vector>

using namespace sf;
using namespace std;

class Fight
{
protected:
	static vector<InputManager::Input> _sequence;

public:
	static int index;
	static bool hit(InputManager::Input);
	static void setSequence(vector<InputManager::Input> moves);
};