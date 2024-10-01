#include <unistd.h>

void expand(char *str)
{
	int i = 0;
	int flag;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			flag = 1;
		else
		{
			if (flag)
				write(1, "   ", 3);
			flag = 0;
			write(1, &str[i], 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		expand(argv[1]);
	write(1, "\n", 1);
	return (0);
}
