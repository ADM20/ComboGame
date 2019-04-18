#include "controls.h"
using namespace std;
using namespace sf;


vector<vector<bool>> InputManager::triggers = {};


void InputManager::Init()
{
	for (int i = 0; i < numberOfActions; i++)
	{
		vector<bool> line;
		for (int j = 0; j < 3; j++)
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

vector<bool> InputManager::GetInputSet(const InputManager::Input index)
{
	return InputManager::triggers[index];
}

bool InputManager::GetInput(const InputManager::Input index, const InputManager::Mode mode)
{
	return InputManager::triggers[index][mode];
}


void InputManager::Test()
{
	std::cout << "Test() called" << std::endl;
}


void InputManager::Rebind(const InputManager::Input action, const sf::Keyboard::Key key)
{
	InputManager::bindings[action] = key;
}


void InputManager::Update()
{
	for each(pair<InputManager::Input, Keyboard::Key> p in bindings)
	{
		//set triggers true of false for key pressed
		if (Keyboard::isKeyPressed(p.second))
		{
			//check if it was already pressed
			bool pressedLastFrame = InputManager::triggers[p.first][1];
			//set it
			InputManager::triggers[p.first][0] = true;

			//if it was not pressed last frame set flag for key down this frame to true, else to false
			if (!pressedLastFrame)
				InputManager::triggers[p.first][1] = true;
			else
				InputManager::triggers[p.first][1] = false;
		}
		else
		{
			//set trigger to false and key down this frame to false
			InputManager::triggers[p.first][0] = false;
			InputManager::triggers[p.first][1] = false;
		}
	}

	//debug print
	//InputManager::print();
}

void InputManager::print()
{
	for (int i = 0; i < numberOfActions; i++)
	{
		vector<bool> line;
		for (int j = 0; j < 3; j++)
		{
			cout << "pressed: " << InputManager::triggers[i][j] << ",   ";
		}
		cout << endl;
	}
}

//default bindings
map<InputManager::Input, Keyboard::Key> InputManager::bindings =
{
	{InputManager::UP, Keyboard::W },
	{InputManager::DOWN, Keyboard::S },
	{InputManager::LEFT, Keyboard::A },
	{InputManager::RIGHT, Keyboard::D },
	{InputManager::LIGHT, Keyboard::Numpad7 },
	{InputManager::MEDIUM, Keyboard::Numpad8 },
	{InputManager::HEAVY, Keyboard::Numpad9 },
	{InputManager::KICK, Keyboard::Add},
	{InputManager::CONFIRM, Keyboard::Enter },
};


