#include "controls.h"
using namespace std;
using namespace sf;
sf::Clock clockTime;//start a timer

vector<vector<bool>> InputManager::triggers = {};
bool _takeInput = false;
float _grace = 0.2f;

InputManager::Input InputManager::InputPressed = InputManager::Input::Confirm;

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

//tell if at least one input bind is pressed
bool InputManager::AnyInputPressed()
{
	for(int i = 0; i < InputManager::triggers.size(); i++)
	{
		if (triggers[i][0])
			return true;
	}
	return false;
}



void InputManager::Test()
{
	std::cout << "Test() called" << std::endl;
}

//Rebind key
void InputManager::RebindKey(const InputManager::Input action, const sf::Keyboard::Key key)
{
	InputManager::keyBindings[action] = key;
}

//Overload to rebind Joystick controls
void InputManager::RebindKey(const InputManager::Input action, const InputManager::JoystickButton button)
{
	InputManager::gamepadBindings[action] = button;
}

int InputManager::PollJoystick()
{
	//for each button on the controller
	for (int i = 0; i < InputManager::JoystickButton::JoyRight + 1; i++)
	{
		//if a button is pressed return it's index
		if (sf::Joystick::isButtonPressed(0, i))
		{
			return i;
		}
	}

	//if no buttons pressed reutrn -1
	return -1;

}


void InputManager::Update()
{
	for each(pair<InputManager::Input, Keyboard::Key> p in keyBindings)
	{
		//set triggers true of false for key pressed
		if (Keyboard::isKeyPressed(p.second))
		{
			//allert that a button is pressed
			InputPressed = p.first;

			//check if it was already pressed
			bool pressedLastFrame = InputManager::triggers[p.first][1];
			//set it
			InputManager::triggers[p.first][0] = true;

			//if it was not pressed last frame set flag for key down this frame to true, else to false
			if (!pressedLastFrame)
			{
				InputManager::triggers[p.first][1] = true;
				//cout << p.first << ":" << InputManager::triggers[p.first][1]<< endl;
			}
			else
			{
				InputManager::triggers[p.first][1] = false;
				//cout << p.first << ":" << InputManager::triggers[p.first][1] << endl;
			}
		}
		else
		{
			//set trigger to false and key down this frame to false
			InputManager::triggers[p.first][0] = false;
			InputManager::triggers[p.first][1] = false;
		}
	}

	//cout << "left "<< ": " << InputManager::GetInput(InputManager::Input::Left, InputManager::Mode::IsPressed)<<endl;

	if (Joystick::isConnected(0))
	{
		for each(pair<InputManager::Input, InputManager::JoystickButton> p in gamepadBindings)
		{
			//set triggers true of false for key pressed
			if (Joystick::isButtonPressed(0, p.second))
			{
				//allert that a button is pressed
				InputPressed = p.first;

				//check if it was already pressed
				bool pressedLastFrame = InputManager::triggers[p.first][1];
				//set it
				InputManager::triggers[p.first][0] = true;

				//if it was not pressed last frame set flag for key down this frame to true, else to false
				if (!pressedLastFrame)
				{
					InputManager::triggers[p.first][1] = true;
					//cout << p.first << ":" << InputManager::triggers[p.first][1] << endl;
				}
				else
				{
					InputManager::triggers[p.first][1] = false;
					//cout << p.first << ":" << InputManager::triggers[p.first][1] << endl;
				}
			}
			else
			{
				//set trigger to false and key down this frame to false
				InputManager::triggers[p.first][0] = false;
				InputManager::triggers[p.first][1] = false;
			}
		}
		
		//cout << "left " << ": " << InputManager::GetInput(InputManager::Input::Left, InputManager::Mode::IsPressed)<<endl;
	}
	if ((_grace - clockTime.getElapsedTime().asSeconds()) <= 0.0f)//if we are not in grace period anymore
	{
		_takeInput = false;//stop taking inputs
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

bool InputManager::getBool()//return true if inputs are open, false if you should not take user input
{
	return _takeInput;
}

void InputManager::setBool(float grace)//take in a grace period, set bool to true for that amount of time
{
	_grace = grace;
	_takeInput = true;
	clockTime.restart();//start the clock!
}

//default bindings
map<InputManager::Input, Keyboard::Key> InputManager::keyBindings =
{
	{InputManager::Up, Keyboard::W },
	{InputManager::Down, Keyboard::S },
	{InputManager::Left, Keyboard::A },
	{InputManager::Right, Keyboard::D },
	{InputManager::LightPunch, Keyboard::Numpad4 },
	{InputManager::MediumPunch, Keyboard::Numpad5 },
	{InputManager::HeavyPunch, Keyboard::Numpad6 },
	{InputManager::LightKick, Keyboard::Numpad1},
	{InputManager::MediumKick, Keyboard::Numpad2},
	{InputManager::HeavyKick, Keyboard::Numpad3},
	{InputManager::Confirm, Keyboard::Enter },
};

map<InputManager::Input, InputManager::JoystickButton> InputManager::gamepadBindings =
{
	{InputManager::Up, InputManager::JoystickButton::JoyUp },
	{InputManager::Down, InputManager::JoystickButton::JoyDown },
	{InputManager::Left, InputManager::JoystickButton::JoyLeft },
	{InputManager::Right, InputManager::JoystickButton::JoyRight },
	{InputManager::LightPunch, InputManager::JoystickButton::X },
	{InputManager::MediumPunch, InputManager::JoystickButton::Y },
	{InputManager::HeavyPunch, InputManager::JoystickButton::RB },
	{InputManager::LightKick, InputManager::JoystickButton::A},
	{InputManager::MediumKick, InputManager::JoystickButton::B},
	{InputManager::HeavyKick, InputManager::JoystickButton::LB},
	{InputManager::Confirm, InputManager::JoystickButton::A },
};

