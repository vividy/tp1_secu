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

	if (pos > 8)
		return ("aa");
	cout << "pos: " << pos << "\t hash:" << hash << endl;
	for (int i = 0; i < str.length(); ++i)
	{
		tmp.clear();
		tmp = hash;
		tmp += str[i];
		end = recurs(str, stealPass, tmp, pos + 1);
	}
	//    if (md5(hash) = stealpass)
	return ("b");
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

	if (ac > 1)
		stealPass = av[1];
	else
	  return (-1);
	// for (int y = 0; y < 8; ++y)
	// {
	// 	for (int i = 0; i < str.length(); ++i)
	// 	 {
		   
		   
	// 	 }
	// }
	recurs(str, stealPass, hash, 0);
	return (0);
}
