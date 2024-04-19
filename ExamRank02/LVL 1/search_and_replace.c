#include "unistd.h"

void searchr(char *str, char *no, char *si)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (str[i] == no[0])
                str[i] = si[0];
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 4 && !argv[2][1] && !argv[3][1])
    {
        searchr(argv[1], argv[2], argv[3]);
    }
    write(1, "\n", 1);
    return (0);
}