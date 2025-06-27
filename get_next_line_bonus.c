#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

char *get_next_line_bonus(int fd)
{
	int	bytes;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	static char	*stash[10240];

	if (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash[fd], '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash[fd]);
			stash[fd] = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}

char *get_next_line(int fd)
{
	return (get_next_line_bonus(fd));
}
