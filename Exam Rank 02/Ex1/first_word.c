#include <unistd.h>

void first(char *str)
{
	int i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] >= 33 && str[i] <= 127 && str[i] != ' ' && str[i] != '\t')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		first(argv[1]);
	write(1, "\n", 1);
	return (0);
}
