#include "unistd.h"


void repeating(int i, char c)
{
    while (i > 0)
    {
        write(1, &c, 1);
        i--;
    }
}

void repeat_alpha(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            repeating(str[i] + 1 - 'a', str[i]);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            repeating(str[i] + 1 - 'A', str[i]);
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
        repeat_alpha(argv[1]);
    write(1, "\n", 1);
    return (0);
}