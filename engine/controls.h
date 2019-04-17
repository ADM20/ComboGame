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
	enum Input
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		LIGHT,
		MEDIUM,
		HEAVY,
		KICK,
		CONFIRM
	};

	static vector<vector<bool>> GetAllInputs();
	static vector<bool> GetInput(const InputManager::Input input);
	static void Init();
	static void Rebind(const InputManager::Input, const sf::Keyboard::Key);
	static void Update();

	
	static void Test();


private:
	static vector<vector<bool>> triggers;
	static void print();
	//[a][b]
	//where a is the line for a particular action
	//and b is the index for bools
	//0 is whether its active, 1, is whetehr it was pressed down this frame, 2 is whether it is supposed to be next to be pressed or not
	static map<InputManager::Input, sf::Keyboard::Key> bindings;
	static int const numberOfActions = 9;

};