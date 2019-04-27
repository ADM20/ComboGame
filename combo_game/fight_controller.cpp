#include "fight_controller.h"


int Fight::index = 0;
vector<InputManager::Input> Fight::_sequence = {};

void Fight::setSequence(vector<InputManager::Input> moves)
{
	_sequence = moves;
}

bool Fight::hit(InputManager::Input move)
{
	if (move == _sequence[index])
	{
		index++;
		return true;
	}
	else
	{
		return false;
	}
}