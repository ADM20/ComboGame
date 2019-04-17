#include "controls.h"
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;

int numberOfActions = 9;



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


