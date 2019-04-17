#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class InputManager {
public:

	static vector<vector<bool>> GetAllInputs();
	static vector<bool> GetInput(const int input);
	static void Init();

	enum Input
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		LIGHT,
		MEDIUM,
		HEAVY,
		KICK
	};
	static void Test();


private:
	static vector<vector<bool>> triggers;
	//[a][b]
	//where a is the line for a particular action
	//and b is the index for bools
	//0 is whether its active, 1, is whetehr it was pressed down this frame, 2 is whether it is supposed to be next to be pressed or not

};