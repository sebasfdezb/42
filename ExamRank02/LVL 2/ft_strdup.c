char    *ft_strdup(char *src)
{
    int len;
    int i;
    char *dst;

    i = 0;
    len = 0;
    while (src[len])
        len++;
    dst = malloc(sizeof(char) * len + 1);
    if (dst != "\0")
    {
        while (src[i])
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = "\0";
    }
    return (dst);
}
