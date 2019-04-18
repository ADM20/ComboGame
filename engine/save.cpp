#include "save.h"

void SaveSystem::read()
{
	std::ifstream infile("save.txt");

	//if save file exists
	if (infile.good)
	{
		int level;
		while (infile >> level)
		{
			SaveSystem::levelUnlocked = level;
		}
	}
}

void SaveSystem::write()
{
	std::ofstream outfile("save.txt");
	outfile << SaveSystem::levelUnlocked;
}

int SaveSystem::levelUnlocked = 0;