#include <unistd.h>

void rot(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] + 13 - 'a') % 26 + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
                        str[i] = (str[i] + 13 - 'A') % 26 + 'A';
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rot(argv[1]);
	write(1, "\n", 1);
	return (0);
}
