#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace std;

class InputManager {
public:
	enum JoystickButton
	{
		A,
		B,
		Y,
		X,
		LB,
		RB,
		LeftStick,
		RightStick,
		Start,
		Back,
		XboxButton,
		JoyUp,
		JoyDown,
		JoyLeft,
		JoyRight
	};
	enum Mode
	{
		IsPressed,
		DownThisFrame,
		NextMove
	};

	enum Input
	{
		Up,
		Down,
		Left,
		Right,
		LightPunch,
		MediumPunch,
		HeavyPunch,
		LightKick,
		MediumKick,
		HeavyKick,
		Confirm
	};

	static vector<vector<bool>> GetAllInputs();
	//get one bool corresponding to a specific mode for an input
	static bool GetInput(const InputManager::Input input, const InputManager::Mode mode);
	//get the whole set of bools as a vector for one input type
	static vector<bool> GetInputSet(const InputManager::Input input);
	static void Init();
	static void RebindKey(const InputManager::Input, const sf::Keyboard::Key);
	static void RebindKey(const InputManager::Input action, const InputManager::JoystickButton button);
	static void Update();
	static int PollJoystick();
	
	static void Test();


private:
	static vector<vector<bool>> triggers;
	static void print();
	//[a][b]
	//where a is the line for a particular action
	//and b is the index for bools
	//0 is whether its active, 1, is whetehr it was pressed down this frame, 2 is whether it is supposed to be next to be pressed or not
	static map<InputManager::Input, sf::Keyboard::Key> keyBindings;
	static map<InputManager::Input, InputManager::JoystickButton> gamepadBindings;
	static int const numberOfActions = 11;

};