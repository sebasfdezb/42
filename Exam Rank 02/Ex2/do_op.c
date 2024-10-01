#include <stdio.h>
#include <stdlib.h>

void doop(int n1, char c, int n2)
{
	if (c == '+')
		printf("%d", n1 + n2);
	if (c == '-')
                printf("%d", n1 - n2);
	if (c == '*')
                printf("%d", n1 * n2);
	if (c == '/')
                printf("%d", n1 / n2);
	if (c == '%')
                printf("%d", n1 % n2);
}

int main(int argc, char **argv)
{
	if (argc == 4)
		doop(atoi(argv[1]), argv[2][0], atoi(argv[3]));
	printf("\n");
	return (0);
}
