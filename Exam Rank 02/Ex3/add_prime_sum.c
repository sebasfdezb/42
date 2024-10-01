#include <unistd.h>

int ft_atoi(char *str)
{
	int result = 0;
	int i = 0;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
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

int is_prime(int n)
{
	int i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void add(int n)
{
	if (n == 0)
		ft_putnbr(0);
	int sum = 0;
	while (n > 0)
	{
		if (is_prime(n))
			sum = sum + n;
		n--;
	}
	ft_putnbr(sum);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		add(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
