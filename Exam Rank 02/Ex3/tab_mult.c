#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;
	int sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void tab(int n)
{
	int i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		i++;
		write(1, "\n", 1);
	}

}

int main(int argc, char **argv)
{
	if (argc == 2)
		tab(ft_atoi(argv[1]));
	else
		write(1, "\n", 1);
	return (0);
}
