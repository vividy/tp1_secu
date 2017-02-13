#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <thread>
#include <mutex>
#include "./md5.h"

using namespace std;

bool	isFined  = false;
string	Password = "";
mutex	isFined_mutex;

string	recurs(string str, string stealPass, string hash, int pos, int num)
{
	string	end;
	string	tmp;

//	cout << "num:" << num << "\tpos:" << pos << "\t hash:" << hash << endl;
	if (md5(hash) == stealPass)
	{
		isFined_mutex.lock();
		isFined = true;
		Password = hash;
		isFined_mutex.unlock();
		return (hash);
	}
	if (pos > 6)
		return ("");
	//	cout << "pos: " << pos << "\t hash:" << hash << "\t stealPass:" << stealPass << endl;
	for (int i = 0; i < str.length(); ++i)
	{
		isFined_mutex.lock();
		if (isFined == true)
		{
			isFined_mutex.unlock();
			return ("");
		}
		isFined_mutex.unlock();
		tmp.clear();
		tmp = hash;
		tmp += str[i];
		end = recurs(str, stealPass, tmp, pos + 1, num);
		if (end != "")
			return (end);
	}
	return ("");
}

void	threadHandler()
{
	cout << "hello world" << endl;
}

int		main(int ac, char **av)
{
	string		stealPass;
	string		str("abcdefghijklmnopqrstuvwxyz0123456789!@#$%&*");
	string		hash("");
	thread		calc[46];

	if (ac > 1)
		stealPass = av[1];
	else
	  return (-1);

	for (int i = 0; i < str.size(); ++i)
	{
		hash = str[i];
		calc[i] = thread(&recurs, str, stealPass, hash, 0, i);
	}
	for (int i = 0; i < str.size(); ++i)
	{
		calc[i].join();
	}

	if (Password != "")
		cout << "Password found:" << Password << endl;
	else
		cout << "Password not found..." << endl;
	return (0);
}
