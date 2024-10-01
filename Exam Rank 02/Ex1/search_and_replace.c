#include <unistd.h>

void search(char *str, char a, char b)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 4 && !argv[2][1] && !argv[3][1])
		search(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);
	return (0);
}
