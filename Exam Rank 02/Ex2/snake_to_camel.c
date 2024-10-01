#include <unistd.h>

void snake(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '_')
		{
			i++;
			str[i] = str[i] - 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		snake(argv[1]);
	write(1, "\n", 1);
	return (0);
}
