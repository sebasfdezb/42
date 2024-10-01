#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;

	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void printhex(int n)
{
	char hex[] = "0123456789abcdef";
	if (n >= 16)
		printhex(n / 16);
	write(1, &hex[n % 16], 1);
	
}

int main(int argc, char **argv)
{
	if (argc == 2)
		printhex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
