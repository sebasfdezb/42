#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int i = 0;
	int step = 1;
	int n = abs((end - start)) + 1;
	int *range = (int *)malloc(sizeof(int) * n);

	if (start < end)
		step = -1;
	if (range)
	{
		while (i < n)
		{
			range[i] = end;
			end = end + step;
			i++;
		}
	}
	return (range);
}
