#include "controls.h"
using namespace std;



bool InputManager::instanceFlag = false;
InputManager* InputManager::single = NULL;
InputManager* InputManager::getInstance()
{
	if (!instanceFlag)
	{
		single = new InputManager();
		instanceFlag = true;
		return single;
	}
	else
	{
		return single;
	}
}


void InputManager::Test()
{
	std::cout << "Test() called" << std::endl;
}


