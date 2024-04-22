#include <unistd.h>

int main(int argc, char **argv)
{
    int seen[256] = {0};
    char result[256];
    int i;
    int j;

    i = 0;
    j = 0;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }

    while (argv[1][i])
    {
        if (!seen[argv[1][i]])
        {
            result[j++] = argv[1][i];
            seen[argv[1][i]] = 1;
        }
        i++;
    }
    i = 0;

    while (argv[2][i])
    {
        if (!seen[argv[2][i]])
        {
            result[j++] = argv[2][i];
            seen[argv[2][i]] = 1;
        }
        i++;
    }
    result[j] = '\0';
    i = 0;

    while (result[i])
    {
        write(1, &result[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}