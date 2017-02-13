#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(int ac, char** av)
{
	char c;
	for (int a = 1; a < 26; ++a)
	{
		for (int i = 1; i < ac; ++i)
		{
			for (int y = 0; y < strlen(av[i]); ++y)
			{
				c = av[i][y];
				c -= 65;
				c += a;
				c = c % 26;
				c += 65;
				write(1, &c, 1);
			}
		}
		write(1, "\n", 1);
	}
	return(0);
}