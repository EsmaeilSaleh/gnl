#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
    char buffer[BUFFER_SIZE + 1];
    char *line;
    int bytes;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes = 1;
    while (!ft_strchr(stash, '\n') && bytes > 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
            return (NULL);
        buffer[bytes] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    line = extract_line(stash);
    stash = update_stash(stash);
    return (line);
}
