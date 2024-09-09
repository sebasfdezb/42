#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		counter;
	char		*dest;
	char		*srce;

	if (!src && !dst)
		return (0);
	counter = 0;
	dest = (char *)dst;
	srce = (char *)src;
	while (counter < n)
	{
		dest[counter] = (char)srce[counter];
		counter++;
	}
	return (dst);
}