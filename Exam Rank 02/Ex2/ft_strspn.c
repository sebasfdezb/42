#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (char *)&s[i];
		i++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	while (s[i])
	{
		if (ft_strchr(accept, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}
