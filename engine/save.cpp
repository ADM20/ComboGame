#include "save.h"

void SaveSystem::read()
{
	std::ifstream infile("save.txt");

	//if save file exists
	if (infile.good())
	{
		int level;
		while (infile >> level)
		{
			SaveSystem::levelUnlocked = level;
		}
		std::cout << "SaveSystem: Read Good" << std::endl;
	}
	else
	{
		std::cout << "SaveSystem: Read Failed" << std::endl;
	}
}

void SaveSystem::write()
{
	std::ofstream outfile;
	outfile.open("save.txt");
	outfile << SaveSystem::levelUnlocked;
	std::cout << "SaveSystem: Write" << std::endl;
	outfile.close();
}

int SaveSystem::levelUnlocked = 0;