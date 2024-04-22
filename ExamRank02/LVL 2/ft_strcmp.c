#include "unistd.h"
#include "stdio.h"

int    ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int main(void)
{
    char x [] = "HolA";
    char y [] = "Hola";
    int a = ft_strcmp(x, y);
    printf("%d", a);
    return (0);
}