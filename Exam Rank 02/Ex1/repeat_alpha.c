#include <unistd.h>

void repeat(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			count = str[i] - 'a' + 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
                        count = str[i] - 'A' + 1;
		else
			count = 1;
		while (count--)
			write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		repeat(argv[1]);
	write(1, "\n", 1);
	return (0);
}
