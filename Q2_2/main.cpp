#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <thread>
#include <mutex>
#include <map>
#include "./md5.h"

using namespace std;

int	isFined  = 5;
mutex	isFined_mutex;

string	recurs(string &str, string *stealPass, string &hash, int pos, int &num, int pow)
{
	string	end;
	string	tmp;

//	cout << "num:" << num << "\tpos:" << pos << "\t hash:" << hash << endl;
	for (int i = 0; i < stealPass->size(); ++i)
	{
		if (md5(hash) == stealPass[i])
		{
			isFined_mutex.lock();
			isFined -= 1;
			isFined_mutex.unlock();

			std::ofstream outfile (stealPass[i] + ".txt");
			outfile << hash << std::endl;
			outfile.close();
		}
	}

	if (pos > 6)
		return ("");
	for (unsigned int i = pow; i < str.length(); i++)
	{
		isFined_mutex.lock();
		if (isFined == 0)
		{
			isFined_mutex.unlock();
			return ("");
		}
		isFined_mutex.unlock();
		tmp.clear();
		tmp = hash;
		tmp += str[i];
		end = recurs(str, stealPass, tmp, pos + 1, num, pow);
		if (end != "")
			return (end);
	}
	return ("");
}

void	threadHandler(string str, string *stealPass, string hash, int num, int pow)
{
	recurs(str, stealPass, hash, 0, num, pow);
}

int		main(int ac, char **av)
{
	string		stealPass[5];
	string		str("abcdefghijklmnopqrstuvwxyz0123456789!@#$%&*");
	string		hash("");
	thread		*calc = new thread[str.size()];
	thread		*calcx = new thread[str.size()];
	
	stealPass[0] = "3692af23f6e25ff3e4f6fc07d1952267";
	stealPass[1] = "b8a1c63b24574a4b5f041cc6940035e9";
	stealPass[2] = "eeb7a3effbc7883db281a859bfa8b8f9";
	stealPass[3] = "15a196696cc990f8796871a1001eb21f";
	//stealPass[4] = "c2b7443aeba6de69bcba5af76c5bfd5a";
	stealPass[4] = "ee164042f1ac00236cc00e3a46b37d15";

	for (unsigned int i = 0; i < str.size(); ++i)
	{
		hash = str[i];
		calc[i] = thread(&threadHandler, str, stealPass, hash, i, 0);
		//calcx[i] = thread(&threadHandler, str, stealPass, hash, i, 1);
	}
	for (unsigned int i = 0; i < str.size(); ++i)
	{
		calc[i].join();
		//calcx[i].join();
	}

	return (0);
}
