#include <iostream>
#include <fstream>  

using namespace std;

class SaveSystem {
public:
	static int levelUnlocked;
	static void write();
	static void read();
};