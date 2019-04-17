#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class InputManager {
public:
	static InputManager *getInstance();
	vector<string> getInputs();
	void Test();

	~InputManager() 
	{
		std::cout << "INPUT MANAGER INTITIALISED" << std::endl;
		instanceFlag = false; 
	};

private:
	InputManager() 
	{
		std::cout << "CONSTRUCTOR CALLED" << std::endl;
	};
	static bool instanceFlag;
	static InputManager *single;

	
	
	map<int, string> actions;
};