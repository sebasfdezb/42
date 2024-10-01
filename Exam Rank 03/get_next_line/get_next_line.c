#include "get_next_line.h"

char *ft_strdup(char *str)
{
	int i = 0;
	char *result;

	while (str[i])
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos;
	static int buffer_read;
	int i = 0;
	char line[70000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
