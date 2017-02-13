#include <iostream>
#include <fstream>
#include <list>
#include "./md5.h"

using namespace std;
int	main()
{
	fstream		fr("basbes.txt");
	string		dicoPass;
	string		stealPass;
	
	while (getline(fr, stealPass))
	{
		fstream		fs("mots-8-et-moins.txt");
		while (getline(fs, dicoPass) && md5(dicoPass) != stealPass);
			if (md5(dicoPass) == stealPass)
				cout << "password: " << dicoPass << "\t hash: " << stealPass << endl;
		if (md5(dicoPass) != stealPass)
			cout << "hash not found: " << stealPass << endl;
	}
	return (0);
}