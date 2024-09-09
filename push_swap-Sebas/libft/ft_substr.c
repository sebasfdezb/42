#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	size = ft_strlen(s);
	if (size <= start)
		return (ft_strdup(""));
	if (size - start < len)
		len = size - start;
	substr = (char *) malloc(len + 1);
	if (!substr)
		return (0);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}