#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen (s1) + 1;
	s2 = malloc(len * sizeof(char));
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, len);
	return ((char *)s2);
}