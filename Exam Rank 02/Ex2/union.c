#include <unistd.h>

void ft_union(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	unsigned char seen[256] = {0};

	while (s1[i])
	{
		if (!seen[(unsigned char)s1[i]])
		{
			write(1, &s1[i], 1);
			seen[(unsigned char)s1[i]] = 1;
		}
		i++;

	}
	while (s2[j])
        {
                if (!seen[(unsigned char)s2[j]])
                {
                        write(1, &s2[j], 1);
                        seen[(unsigned char)s2[j]] = 1;
                }
                j++;

        }
}

int main(int argc, char **argv)
{	
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
