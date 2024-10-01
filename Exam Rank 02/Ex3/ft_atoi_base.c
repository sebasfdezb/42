#include <stdlib.h>
#include <stdio.h>


char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int get_digit(char c, int base)
{
	int max_digit;

	if (base <= 10)
		max_digit = base - 1 + '0';
	else
		max_digit = base - 10 - 1 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (c + 10 - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	if (str == NULL || str_base < 2 || str_base > 10)
		return (0);
	int sign = 1;
	int result = 0;
	int i = 0;
	int digit;

	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		digit = get_digit(to_lower(str[i]), str_base);
		if (digit == -1)
			break ;
		result = result * str_base + digit;
		i++;
	}
	return (result * sign);
}
