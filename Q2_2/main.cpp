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

void	recurs(string &str, string *stealPass, string &hash, int pos, int &num, int pow)
{
	string	tmp;
	string	myMd5;
//	cout << "num:" << num << "\tpos:" << pos << "\t hash:" << hash << endl;
	myMd5 = md5(hash);
	for (int i = 0; i < 5; ++i)
	{
		if (myMd5 == stealPass[i])
		{
			isFined_mutex.lock();
			isFined -= 1;
			isFined_mutex.unlock();

			std::ofstream outfile (stealPass[i] + ".txt");
			outfile << hash << std::endl;
			outfile.close();
			cout << "password fined:" << hash << "\t" << stealPass[i] << endl;
		}
	}

	if (pos > 6)
		return ;
	else if (pos < 3)
	  cout << "thread no: " << num << "\thash actual: " << hash <<  endl;
	for (unsigned int i = pow; i < 43; i++)
	{
		if (isFined_mutex.try_lock() == true)
		{
			if (isFined == 0)
			{
				isFined_mutex.unlock();
				return ;
			}
			isFined_mutex.unlock();
		}
		tmp.clear();
		tmp = hash;
		tmp += str[i];
		recurs(str, stealPass, tmp, pos + 1, num, pow);
	}
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
	
	stealPass[0] = "3692af23f6e25ff3e4f6fc07d1952267";
	stealPass[1] = "b8a1c63b24574a4b5f041cc6940035e9";
	stealPass[2] = "eeb7a3effbc7883db281a859bfa8b8f9";
	stealPass[3] = "15a196696cc990f8796871a1001eb21f";
	stealPass[4] = "a98a747db71f95aa57506d2aa7f07e50";
	//stealPass[4] = "ee164042f1ac00236cc00e3a46b37d15";
	
	for (unsigned int i = 0; i < str.size(); ++i)
	  {
	    hash = str[i];
	    calc[i] = thread(&threadHandler, str, stealPass, hash, i, 0);
	  }
	for (unsigned int i = 0; i < str.size(); ++i)
	  {
	    calc[i].join();
	  }
	return (0);
}
