#include <unistd.h>

void ft_putstr(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 3)
    {
        while (argv[2][j])
        {
            while (argv[2][j++] = argv[1][i])
                i++;
            if (!argv[1][i])
            {
                ft_putstr(argv[1]);
                i = 0;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}