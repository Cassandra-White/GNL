

#include "get_next_line.h"

size_t	ft_strlen(const char *s1)
{
	unsigned int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}


int		ft_end(char **line, char **save, int fd, int bytes)
{
	if (bytes == BUFFER_SIZE)
		return (get_next_line(fd, line));
	*line = ft_strdup(save[fd]);
	free(save[fd]);
	save[fd] = NULL;
	return (0);
}

int		ft_line(char **line, char **save, int fd, int i)
{
	char 	*temp;

	*line = ft_substr(save[fd], 0, i);
	temp = ft_strdup(save[fd] + i + 1);
	free(save[fd]);
	save[fd] = temp;
	if (save[fd][0] == '\0')
	{
		free(save[fd]);
		save[fd] = NULL;
	}
	return (1);
}


int	ft_next_step(char **line, char **save, int fd, int bytes)
{
	int		i;

	i = 0;
	if (bytes == 0 && (save[fd] == NULL || save[fd][0] == '\0'))
	{
		*line = malloc(1);
		**line = '\0';
		return (0);
	}
	
	while (save[fd][i] != '\0' && save[fd][i] != '\n')
		i++;
	return (save[fd][i] == '\0') ?
		(ft_end(line, save, fd, bytes))
		: (ft_line(line, save, fd, i));

	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[255];
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int		bytes;
	
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((bytes = read(fd, buff, BUFFER_SIZE)) >0)
	{
		buff[bytes] = '\0';
		if (!save[fd])
			save[fd] = ft_malloc_it(1);
		temp = ft_strjoin(save[fd], buff);
		free(save[fd]);
		save[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (bytes < 0)
		return (-1);
	return (ft_next_step(line, save, fd, bytes));
}
