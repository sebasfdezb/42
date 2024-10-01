#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char *result;
	while(src[i])
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result != NULL)
	{
		i = 0;
		while (src[i])
		{
			result[i] = src[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
