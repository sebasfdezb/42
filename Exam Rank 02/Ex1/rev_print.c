#include <unistd.h>

void rev(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev(argv[1]);
	write(1, "\n", 1);
	return (0);
}
