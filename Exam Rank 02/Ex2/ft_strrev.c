char    *ft_strrev(char *str)
{
	int i = 0;
	int len = 0;
	char aux;
	while (str[len])
		len++;
	while (i < len / 2)
	{
		aux = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = aux;
		i++;
	}
	return (str);
}	
