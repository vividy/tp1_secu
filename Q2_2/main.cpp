#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <thread>
#include "./md5.h"

using namespace std;
string	recurs(string str, string stealPass, string hash, int pos)
{
	string	end;
	string	tmp;

	if (md5(hash) == stealPass)
	{
		return (hash);
	}
	if (pos > 7)
		return ("");
	//      	cout << "pos: " << pos << "\t hash:" << hash << "\t stealPass:" << stealPass << endl;
	for (int i = 0; i < str.length(); ++i)
	{
		tmp.clear();
		tmp = hash;
		tmp += str[i];
		end = recurs(str, stealPass, tmp, pos + 1);
		if (end != "")
			return (end);
	}
	return ("");
}

 // void	handle(int num)
 // {
	// recurs(str, stealPass, hash, 0);
 // }

int		main(int ac, char **av)
{
	string		stealPass;
	string		str("abcdefghijklmnopqrstuvwxyz0123456789!@#$%%&*");
	string		hash("");
	thread          calc[46];

	if (ac > 1)
		stealPass = av[1];
	else
	  return (-1);
	for (int y = 0; y < 8; ++y)
	{
	  calc[y] = thread(recurs, ref(str), ref(stealPass), ref(hash), ref(y));
	  // for (int i = 0; i < str.length(); ++i)
	  //   {
	  //   }
	}

	// if ((hash = recurs(str, stealPass, hash, 0)) != "")
	// 	cout << "Password found:" << hash << endl;
	// else
	// 	cout << "Password not found..." << endl;
	return (0);
}
