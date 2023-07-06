#include "rush02.h"

static char	*ft_update_stack(char *stack)
{
	int		i;
	int		j;
	char	*update;

	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	if (stack[i] == '\0')
	{
		free(stack);
		return (NULL);
	}
	update = (char *)malloc(sizeof(char) * (ft_strlen(stack) - i + 1));
	if (update == NULL)
		return (NULL);
	i++;
	j = 0;
	while (stack[i] != '\0')
		update[j++] = stack[i++];
	update[j] = '\0';
	free(stack);
	return (update);
}

static char	*ft_get_line(char *stack)
{
	char	*line;
	int		i;

	if (stack[0] == '\0')
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_read_file(int fd, char *stack)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			break ;
		buffer[read_bytes] = '\0';
		stack = ft_strjoin(stack, buffer);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stack);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stack = ft_read_file(fd, stack);
	if (stack == NULL)
		return (NULL);
	line = ft_get_line(stack);
	stack = ft_update_stack(stack);
	return (line);
}
