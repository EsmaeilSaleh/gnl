#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int			bytes;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
