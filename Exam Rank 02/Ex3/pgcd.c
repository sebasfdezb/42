#include <stdio.h>
#include <stdlib.h>

void pgcd(int n1, int n2)
{
	if (n1 > 0 && n2 > 0)
	{
		while (n1 != n2)
		{
			if (n1 > n2)
				n1 = n1 - n2;
			else
				n2 = n2 - n1;
		}
		printf("%d", n1);
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
