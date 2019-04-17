#include "controls.h"
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;

int numberOfActions = 9;

bool InputManager::instanceFlag = false;
InputManager* InputManager::single = NULL;
InputManager* InputManager::getInstance()
{
	if (!instanceFlag)
	{
		single = new InputManager();
		instanceFlag = true;
		InputManager::init();
		return single;
	}
	else
	{
		return single;
	}
}

void InputManager::Init()
{
	for (int i = 0; i < numberOfActions; i++)
	{
		vector<bool> line;
		for (int j = 0; j < 4; j++)
		{
			line.push_back(false);
		}

		InputManager::triggers.push_back(line);
	}

}

vector<vector<bool>> InputManager::GetAllInputs()
{
	return InputManager::triggers;
}

vector<bool> InputManager::GetInput(const int index)
{
	return InputManager::triggers[index];
}


void InputManager::Test()
{
	std::cout << "Test() called" << std::endl;
}


