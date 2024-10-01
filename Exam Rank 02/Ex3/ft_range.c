#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int i = 0;
	int step = 1;
	int *range;
	int n = abs((end - start) + 1);
	range = (int *)malloc(sizeof(int) * (n + 1));
	if (start > end)
		step = -1;
	while (i < n)
	{
		range[i] = start;
		start = start + step;
		i++;
	}
	return (range);
}
